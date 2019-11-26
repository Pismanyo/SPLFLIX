#ifndef SESSION_H_
#define SESSION_H_

#include <vector>
#include <unordered_map>
#include <string>
#include "Action.h"

class User;
class Watchable;

class Session{
public:
    Session(const std::string &configFilePath);
    ~Session();
    void start();
    void exit();
    string getInput2();
    string getInput3();
    unordered_map<string,User*> *getUserMap();
    std::vector<Watchable*> *getContent();
    std::vector<BaseAction*> *actionLog();
    User* getActiveUser();
    int getCounter();
    std::vector<BaseAction*> * getActionsLog();
    void setActiveUser(User *Active);
    void setActionsLog(BaseAction*);
    bool containsUser(std::string);
    User* getUser(std::string);
    void setinput(std::string);
    bool is_number(const std::string& s);
    bool getAgain();
    void setAgain(bool set);
    void setRecommended( Watchable* other);
    Watchable* getRecommended();

private:
    std::vector<Watchable*> content;
    std::vector<BaseAction*> actionsLog;
    std::unordered_map<std::string,User*> userMap;
    User* activeUser;
    string inputs[3];
    int counter;
    bool again;
    Watchable* recommended;
};
#endif