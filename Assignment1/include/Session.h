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
    void setActiveUser(User *Active);
    bool containsUser(std::string);
    User* getUser(std::string);

private:
    std::vector<Watchable*> content;
    std::vector<BaseAction*> actionsLog;
    std::unordered_map<std::string,User*> userMap;
    User* activeUser;
    string inputs[3];
    int counter;
};
#endif