
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
    json why=json::parse(file);
    json  mov=why["movies"];
    int id=0;
    for(auto &run :mov.items())
    {
        json into=run.value();
        Movie *cur=new Movie (id,into["name"],into["length"],into["tags"]);
        content.push_back(cur);
        ++id;

    }
    json tv=why["tv_series"];
        for(auto &nrun :tv.items())
        {
            json into=nrun.value();
            //cout<<into["seasons"]<<endl;
            vector <int> sessions =into["seasons"];
            int counter=1;
            for (int i :sessions)
            {
                for (int epsoidnum=1;epsoidnum<=i;++epsoidnum) {
                  //  cout<<into["name"]<< ","<<into["length"]<< ","<<into["tags"]<<","<<endl;
                    Episode *cur = new Episode(id, into["name"], into["episode_length"], counter,epsoidnum,into["tags"]);
                //    cout<<into["name"]<< ","<<into["name"]<< ","<<into["length"]<<","<<into["length"]<<endl;
                    content.push_back(cur);
                    id++;
                }
                counter++;
            }
        }

}

Session::~Session() {
}

void Session::start() {
    cout<<"SPLFLIX is now on!"<<endl;
    again= false;
    const string na="default";
    activeUser =new LengthRecommenderUser(na);
   // std::pair<std::string,User*> hjh("default",activeUser);
    userMap.insert({"default",activeUser});
    string answer1;

    while (answer1!="exit")
    {
        getline(cin,answer1);
        string word;
        counter=0;
        stringstream iss(answer1);
        while (iss >> word && counter < 4)
            inputs[counter++] = word;

        if (inputs[0].compare("log") == 0) {

        }
        else if (inputs[0].compare("content") == 0) {

        }
        else if (inputs[0].compare("changeuser") == 0) {
        }
        else if (inputs[0].compare("deleteuser") == 0) {
        }
        else if (inputs[0].compare("watch") == 0) {
            Watch *command=new Watch;
            command->act(*this);
            while(again)
            {
                Watch *WatchRecommanded=new Watch;
                WatchRecommanded->act(*this);

            }
        }
        else if (inputs[0].compare("createuser") == 0) {
            CreateUser *command = new CreateUser();
            command->act(*this);
            actionsLog.push_back(command);
        }
        else if (inputs[0].compare("dupuser") == 0) {
        }
        else if (inputs[0].compare("exit") == 0) {
        }
        else if (inputs[0].compare("log") == 0) {
        }
        else if (inputs[0].compare("watchhist") == 0) {
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

std::vector<BaseAction *> *Session::actionLog() {
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

void Session::setinput(std::string action) {
    inputs[1]=action;

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

void Session::setAgain(bool set) {
    again=set;

}

bool Session::getAgain() {
    return again;
}

