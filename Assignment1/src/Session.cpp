
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

        switch (counter) {
            case 1:
                if (inputs[0].compare("log") == 0) {}
                    //  goodinput=true;
                else if (inputs[0].compare("content") == 0) {}
                //  goodinput = true;
                break;
            case 2:
                if (inputs[0].compare("changeuser") == 0) {}
                    //  goodinput=true;
                else if (inputs[0].compare("deleteuser")) {}
                    //  goodinput=true;
                else if (inputs[0].compare("watch") == 0) {}
                //  goodinput=true;
                break;
            case 3:
                if (inputs[0].compare("createuser") == 0) {
                    CreateUser *what = new CreateUser();
                    what->act(*this);
                    // goodinput=true;
                } else if (inputs[0].compare("dupuser") == 0) {}
                //  goodinput=true;
                break;
        }

       // if(!goodinput) {
        //    cout << "bad input, try again" << endl;
        }
    }
   // exit();


void Session::exit() {
    //delete users
    cout<<"Press any button to start SPLFLIX"<<endl;
    string ans;
    cin>>ans;
    this->start();

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