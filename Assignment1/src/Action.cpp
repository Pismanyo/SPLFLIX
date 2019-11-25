

#include "../include/Action.h"
#include "../include/Session.h"
#include "../include/User.h"

using namespace std;

ActionStatus BaseAction::getStatus() const {
    return status;
}

BaseAction::BaseAction() {
    errorMsg="ERROR!";
    status=PENDING;

}

std::string BaseAction::getErrorMsg() const {
    return errorMsg;
}

void BaseAction::error(const std::string &errorMsg) {
    this->errorMsg=(errorMsg);
    status=ERROR;
}

void BaseAction::complete() {
    status=COMPLETED;

}

std::string Exit::toString() const {
    return std::__cxx11::string();
}

void Exit::act(Session &sess) {

}
CreateUser::CreateUser() : BaseAction (){

}

void CreateUser::act(Session &sess)
    {
        string input2=sess.getInput2();
        string input3=sess.getInput3();
        bool works= false;
       if(sess.getCounter()==3&&sess.getUserMap()->find(input2)==sess.getUserMap()->end())
       {
           if (input3 == "len") {
               LengthRecommenderUser *cur = new LengthRecommenderUser(input2);
               sess.getUserMap()->insert({input2, cur});
               works=true;
           }
           if (input3 == "rer") {
               RerunRecommenderUser *cur = new RerunRecommenderUser(input2);
               sess.getUserMap()->insert({input2, cur});
               works=true;
           } if (input3 == "gen") {
               GenreRecommenderUser *cur = new GenreRecommenderUser(input2);
               sess.getUserMap()->insert({input2, cur});
               works=true;
           }

       }
          if(works)
              complete();
          else {
              //error
          }
    }
ChangeActiveUser::ChangeActiveUser() : BaseAction (){

}
std::string CreateUser::toString() const {
    return std::__cxx11::string();
}

void Watch::act(Session &sess) {

}

std::string Watch::toString() const {
    return std::__cxx11::string();
}
std::string PrintActionsLog::toString() const {
    return std::__cxx11::string();
}

void PrintActionsLog::act(Session &sess) {

}
