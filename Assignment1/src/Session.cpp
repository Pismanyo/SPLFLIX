
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
        vector<int> seasons = into["seasons"];
        int season = 1;
        for (int i :seasons) {
            for (int episodeNum = 1; episodeNum <= i; ++episodeNum) {
                Episode *cur = new Episode(id, into["name"], into["episode_length"], season, episodeNum, into["tags"]);
                content.push_back(cur);
                ++id;
            }
            ++season;
        }
    }
    recommended= nullptr;
    const string na = "default";
    activeUser = new LengthRecommenderUser(na);
    userMap.insert({"default", activeUser});
}

Session::~Session() {
    if(!actionsLog.empty()) {
        for (BaseAction *b: actionsLog) {
            delete b;
            b = nullptr;
        }
    }
    if(!userMap.empty()) {
        for (auto &it : userMap) {
            delete it.second;
            it.second = nullptr;
        }
    }
    if(!content.empty()) {
        for (Watchable *w: content) {
            delete w;
            w = nullptr;
        }
    }
    activeUser = nullptr;
    recommended = nullptr;
}

Session::Session(const Session& other) {
    for (Watchable *w:other.content)
        content.push_back(w->clone());
    for (BaseAction *b : other.actionsLog)
        actionsLog.push_back(b->clone());
    for (const auto &it : other.userMap)
        userMap.insert({it.first, it.second->clone()});
    auto x = userMap.find(other.activeUser->getName());
    activeUser = x->second;
    for (const auto &it : userMap) {
        vector<Watchable*> oldHis = it.second->get_history();
        vector<Watchable*> newHis;
        for(Watchable* w: oldHis){
            for(Watchable* w2: content){
                if(w->getId()==w2->getId())
                    newHis.push_back(w2);
            }
        }
        it.second->updateHistory(newHis);
    }
        if (other.recommended != nullptr) {
            for (Watchable *w: content)
                if (w->getId() == other.recommended->getId())
                    recommended = w;
        }
}

Session& Session::operator=(const Session& other) {
    if (&other == this)
        return *this;
    for (BaseAction *b: actionsLog) {
        delete b;
        b = nullptr;
    }
    actionsLog.clear();
    for (auto &it : userMap) {
        delete it.second;
        it.second = nullptr;
    }
    userMap.clear();
    for (Watchable *w: content) {
        delete w;
        w = nullptr;
    }
    content.clear();

    activeUser = nullptr;
    recommended = nullptr;

    for (Watchable *w:other.content)
        content.push_back(w->clone());
    for (BaseAction *b : other.actionsLog)
        actionsLog.push_back(b->clone());
    for (const auto &it : other.userMap)
        userMap.insert({it.first, it.second->clone()});
    auto x = userMap.find(other.activeUser->getName());
    activeUser = x->second;
    for (const auto &it : userMap) {
        vector<Watchable*> oldHis = it.second->get_history();
        vector<Watchable*> newHis;
        for(Watchable* w: oldHis){
            for(Watchable* w2: content){
                if(w->getId()==w2->getId())
                    newHis.push_back(w2);
            }
        }
        it.second->updateHistory(newHis);
    }
    if (other.recommended != nullptr) {
        for (Watchable *w: content)
            if (w->getId() == other.recommended->getId())
                recommended = w;
    }
    return *this;
}

Session& Session::operator=( Session&& other) {
    if (&other == this)
        return *this;

    for (BaseAction *b: actionsLog) {
        delete b;
        b = nullptr;
    }
    actionsLog.clear();
    for (auto &it : userMap) {
        delete it.second;
        it.second = nullptr;
    }
    userMap.clear();
    for (Watchable *w: content) {
        delete w;
        w = nullptr;
    }
    content.clear();
    for (Watchable *w:other.content) {
        Watchable *cur = w;
        content.push_back(cur);
        w = nullptr;
    }

    for (BaseAction *b : other.actionsLog) {
        BaseAction *cur = b;
        actionsLog.push_back(cur);
        b = nullptr;
    }

    activeUser = other.activeUser;
    for (auto &it : other.userMap) {
        auto w = it.second;
        userMap.insert({it.first, w});
        it.second = nullptr;
    }
    recommended = other.recommended;
    other.activeUser = nullptr;
    other.recommended = nullptr;
    other.actionsLog.clear();
    other.userMap.clear();
    other.content.clear();
    return *this;
}

Session::Session(Session &&other) {
    for (BaseAction *b: actionsLog) {
        delete b;
        b = nullptr;
    }
    actionsLog.clear();
    for (auto &it : userMap) {
        delete it.second;
        it.second = nullptr;
    }
    userMap.clear();
    for (Watchable *w: content) {
        delete w;
        w = nullptr;
    }
    content.clear();

    for (Watchable *w:other.content)
    {
        Watchable *cur=w;
        content.push_back(cur);
        w= nullptr;
    }
    for (BaseAction *b : other.actionsLog) {
        BaseAction *cur=b;
        actionsLog.push_back(cur);
        b= nullptr;
    }

    for (auto &it : other.userMap) {
        auto w=it.second;
        userMap.insert({it.first, w});
        it.second= nullptr;
    }
    activeUser = other.activeUser;
    recommended = other.recommended;
    other.activeUser= nullptr;
    other.recommended=nullptr;

    other.actionsLog.clear();
    other.userMap.clear();
    other.content.clear();

}

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

        if (inputs[0]=="content") {
            PrintContentList *command = new PrintContentList();
            command->act(*this);
            actionsLog.push_back(command);
        }
        else if (inputs[0]=="changeuser") {
            ChangeActiveUser *command = new ChangeActiveUser();
            command->act(*this);
            actionsLog.push_back(command);

        }
        else if (inputs[0]=="deleteuser") {
            DeleteUser *command = new DeleteUser();
            command->act(*this);
            actionsLog.push_back(command);
        }
        else if (inputs[0]=="watch") {
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
        else if (inputs[0]=="createuser") {
            CreateUser *command = new CreateUser();
            command->act(*this);
            actionsLog.push_back(command);
        }
        else if (inputs[0]=="dupuser") {
            DuplicateUser *command = new DuplicateUser();
            command->act(*this);
            actionsLog.push_back(command);
        }
        else if (inputs[0]=="exit") {
            Exit *command = new Exit();
            command->act(*this);
            actionsLog.push_back(command);
        }
        else if (inputs[0]=="log") {
            PrintActionsLog *command = new PrintActionsLog();
            command->act(*this);
            actionsLog.push_back(command);
        }
        else if (inputs[0]=="watchhist") {
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
void Session::setRun(bool running) {
    run=running;
}