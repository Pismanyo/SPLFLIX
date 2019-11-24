
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
    string input1;
    while (answer1!="exit")
    {
        getline(cin,answer1);
        string word;
        counter=0;
        stringstream iss(answer1);
        while (iss >> word&&counter<4)
        {
            if(counter==0)
                input1=word;
            if(counter==1)
                input2=word;
            if(counter==2)
                input3=word;
            counter++;
        }
        if(counter==1)
        {
            if (input1 == "log")
            {
              //  goodinput=true;

            }
            if("content"==input1) {
              //  goodinput = true;
            }
        }
        if(counter=2)
        {
            if (input1 == "changeUser")
            {
               // goodinput=true;


            }
            if("deleteuser"==input1)
            {
            //    goodinput=true;
            }
            if("watch"==input1)
            {
               // goodinput=true;
            }

        }
        if(counter=3)
        {
            if (input1 == "createuser")
            {
                CreateUser *what =new CreateUser();
                what->act(*this);
               // goodinput=true;

            }
            if("dupuser"==input1)
            {
              //  goodinput=true;
            }

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
    return input2;
}
string Session::getInput3() {
    return input3;
}

unordered_map<string, User*> *Session::getUserMap() {
    return &userMap;
}

int Session::getCounter() {
    return counter;
}

