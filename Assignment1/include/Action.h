#ifndef ACTION_H_
#define ACTION_H_

#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Session;

enum ActionStatus{
    PENDING, COMPLETED, ERROR
};


class BaseAction{
public:
    BaseAction();
    virtual BaseAction* duplicate() const = 0;
    ActionStatus getStatus() const;
    virtual void act(Session& sess)=0;
    virtual std::string toString() const=0;
    std::string getErrorMessage() const;
protected:
    void complete();
    void error(const std::string& errorMsg);
    std::string getErrorMsg() const;
private:
    std::string errorMsg;
    ActionStatus status;
};

class CreateUser  : public BaseAction {
public:
    CreateUser();
    virtual CreateUser* duplicate() const ;
    virtual void act(Session& sess);
    virtual std::string toString() const;
};

class ChangeActiveUser : public BaseAction {
public:
    ChangeActiveUser();
    virtual ChangeActiveUser* duplicate() const ;
    virtual void act(Session& sess);
    virtual std::string toString() const;
};

class DeleteUser : public BaseAction {
public:
    DeleteUser();
    virtual DeleteUser* duplicate() const ;
    virtual void act(Session & sess);
    virtual std::string toString() const;
};


class DuplicateUser : public BaseAction {
public:
    DuplicateUser();
    virtual DuplicateUser* duplicate() const ;
    virtual void act(Session & sess);
    virtual std::string toString() const;
};

class PrintContentList : public BaseAction {
public:
    PrintContentList();
    virtual PrintContentList* duplicate() const ;
    virtual void act (Session& sess);
    virtual std::string toString() const;
};

class PrintWatchHistory : public BaseAction {
public:
    PrintWatchHistory();
    virtual PrintWatchHistory* duplicate() const ;
    virtual void act (Session& sess);
    virtual std::string toString() const;
};


class Watch : public BaseAction {
public:
    Watch();
    virtual Watch* duplicate() const ;
    virtual void act(Session& sess);
    virtual std::string toString() const;
};


class PrintActionsLog : public BaseAction {
public:
    PrintActionsLog();
    virtual PrintActionsLog* duplicate() const ;
    virtual void act(Session& sess);
    virtual std::string toString() const;
};

class Exit : public BaseAction {
public:
    Exit();
    virtual Exit* duplicate() const ;
    virtual void act(Session& sess);
    virtual std::string toString() const;
};
#endif