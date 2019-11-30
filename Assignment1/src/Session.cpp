
#include "../include/Session.h"
#include "../include/json.hpp"
#include "../include/Watchable.h"
#include "../include/User.h"
#include <fstream>
#include <sstream>

using json = nlohmann::json ;
using namespace std;

Session::Session(const std::string &configFilePath) {

    fstream file(configFilePath);
    json why = json::parse(file);
    json mov = why["movies"];
    int id = 1;
    for (auto &run :mov.items()) {
        json into = run.value();
        Movie *cur = new Movie(id, into["name"], into["length"], into["tags"]);
        content.push_back(cur);
        ++id;
    }
    json tv = why["tv_series"];
    for (auto &nrun :tv.items()) {
        json into = nrun.value();
        vector<int> sessions = into["seasons"];
        int counter = 1;
        for (int i :sessions) {
            for (int episodeNum = 1; episodeNum <= i; ++episodeNum) {
                Episode *cur = new Episode(id, into["name"], into["episode_length"], counter, episodeNum, into["tags"]);
                content.push_back(cur);
                id++;
            }
            counter++;
        }
    }
    const string na = "default";
    activeUser = new LengthRecommenderUser(na);
    userMap.insert({"default", activeUser});
}

Session::~Session() {
    for (BaseAction *b: actionsLog) {
        delete b;
        b = nullptr;
    }
    for(auto it=userMap.begin(); it!= userMap.end(); ++it) {
        delete it->second;
        it->second = nullptr;
    }
    for(Watchable* w: content) {
        delete w;
        w = nullptr;
    }
}

Session::Session(Session& other) {
    for (Watchable *w:other.content)
        content.push_back(w->clone());
    for (BaseAction *b : other.actionsLog)
        actionsLog.push_back(b->clone());
    for (const auto &it : other.userMap)
        userMap.insert({it.first, it.second->clone()});
    activeUser = other.activeUser->clone();
    recommended = other.recommended->clone();
}

//Session& Session::operator=(const Session& other) {
//    if (&other == this)
//        return *this;
//    for (Watchable *w:other.content)
//        content.push_back(w);
//    for (BaseAction *b : other.actionsLog)
//        actionsLog.push_back(b->clone());
//    for (const auto &it : other.userMap)
//        userMap.insert({it.first, it.second->clone()});
//    auto x = userMap.find(activeUser->getName());
//    activeUser = x->second;
//    recommended = other.recommended->clone();
//    return *this;
//}
void Session::start() {
    cout<<"SPLFLIX is now on!"<<endl;
    watching= false;
    run=true;
    string answer1;
    while (run)
    {
        getline(cin,answer1);
        string word;
        counter=0;
        stringstream iss(answer1);
        while (iss >> word && counter < 4)
            inputs[counter++] = word;

        if (inputs[0].compare("content") == 0) {
            PrintContentList *command = new PrintContentList();
            command->act(*this);
            actionsLog.push_back(command);
        }
        else if (inputs[0].compare("changeuser") == 0) {
            ChangeActiveUser *command = new ChangeActiveUser();
            command->act(*this);
            actionsLog.push_back(command);

        }
        else if (inputs[0].compare("deleteuser") == 0) {
            DeleteUser *command = new DeleteUser();
            command->act(*this);
            actionsLog.push_back(command);
        }
        else if (inputs[0].compare("watch") == 0) {
            Watch *command=new Watch;
            command->act(*this);
            actionsLog.push_back(command);
            while(watching)
            {
                command=new Watch;
                command->act(*this);//
                actionsLog.push_back(command);
            }
        }
        else if (inputs[0].compare("createuser") == 0) {
            CreateUser *command = new CreateUser();
            command->act(*this);
            actionsLog.push_back(command);
        }
        else if (inputs[0].compare("dupuser") == 0) {
            DuplicateUser *command = new DuplicateUser();
            command->act(*this);
            actionsLog.push_back(command);
        }
        else if (inputs[0].compare("exit") == 0) {
            Exit *command = new Exit();
            command->act(*this);
            actionsLog.push_back(command);
        }
        else if (inputs[0].compare("log") == 0) {
            PrintActionsLog *command = new PrintActionsLog();
            command->act(*this);
            actionsLog.push_back(command);
        }
        else if (inputs[0].compare("watchhist") == 0) {
            PrintWatchHistory *command = new PrintWatchHistory();
            command->act(*this);
            actionsLog.push_back(command);
        }
    }
}


string Session::getInput2() {
    return inputs[1];
}
string Session::getInput3() {
    return inputs[2];
}

unordered_map<string, User*> *Session::getUserMap() {
    return &userMap;
}

int Session::getCounter() {
    return counter;
}

std::vector<Watchable *> *Session::getContent() {
    return &content;
}

std::vector<BaseAction *> *Session::getActionsLog() {
    return &actionsLog;
}

User *Session::getActiveUser() {
    return activeUser;
}

void Session::setActiveUser(User *Active) {

    activeUser=Active;
}

bool Session::containsUser(string name) {
    return !(userMap.find(name) == userMap.end());
}

User* Session::getUser(std::string name) {

    return userMap.find(name)->second;
}

bool Session::is_number(const std::string &s) {
    return !s.empty() && std::find_if(s.begin(),
                                      s.end(), [](char c) { return !std::isdigit(c); }) == s.end();
}


void Session::setRecommended(Watchable *other) {
    recommended=other;

}

Watchable *Session::getRecommended() {
    return recommended;
}

void Session::setWatching(bool set) {
    watching=set;

}

bool Session::getWatching() {
    return watching;
}

void Session::setRun(bool runing) {
    run=runing;
}
