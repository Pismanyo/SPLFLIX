

#include "../include/Action.h"
#include "../include/Session.h"
#include "../include/User.h"

using namespace std;

ActionStatus BaseAction::getStatus() const {
    return COMPLETED;
}

BaseAction::BaseAction() {
    errorMsg="ERROR!";
    status=PENDING;

}

std::string BaseAction::getErrorMsg() const {
    return std::__cxx11::string();
}

void BaseAction::error(const std::string &errorMsg) {

}

void BaseAction::complete() {

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
   if(sess.getCounter()==3) {
       if (input3 == "len") {
           LengthRecommenderUser *cur = new LengthRecommenderUser(input2);
           sess.getUserMap()->insert({input2, cur});
       }
       if (input3 == "rer") {
           RerunRecommenderUser *cur = new RerunRecommenderUser(input2);
           sess.getUserMap()->insert({input2, cur});
       } else if (input3 == "gen") {
           GenreRecommenderUser *cur = new GenreRecommenderUser(input2);
           sess.getUserMap()->insert({input2, cur});
       }
       complete();
   }
   else {
       //error();
   }

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
