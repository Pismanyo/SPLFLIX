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
    int getCounter();
private:
    std::vector<Watchable*> content;
    std::vector<BaseAction*> actionsLog;
    std::unordered_map<std::string,User*> userMap;
    User* activeUser;
    std::string input2;
    std:: string input3;
    int counter;

};
#endif