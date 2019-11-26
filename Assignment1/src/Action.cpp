

#include "../include/Action.h"
#include "../include/Session.h"
#include "../include/User.h"
#include "../include/Watchable.h"

using namespace std;

ActionStatus BaseAction::getStatus() const {
    return status;
}




BaseAction::BaseAction(): errorMsg("Error"),status(PENDING) {}

std::string BaseAction::getErrorMsg() const {
    return errorMsg;
}

void BaseAction::error(const std::string &errorMsg) {
    this->errorMsg=(errorMsg);
    status=ERROR;
    cout<<errorMsg<<endl;
}

void BaseAction::complete() {
    status = COMPLETED;
}



CreateUser::CreateUser() : BaseAction (){

}

void CreateUser::act(Session &sess) {
    string input2 = sess.getInput2();
    string input3 = sess.getInput3();
    bool works = false;
    if (sess.getCounter() == 3 && sess.getUserMap()->find(input2) == sess.getUserMap()->end()) {
        if (input3 == "len") {
            LengthRecommenderUser *cur = new LengthRecommenderUser(input2);
            sess.getUserMap()->insert({input2, cur});
            works = true;
        }
        if (input3 == "rer") {
            RerunRecommenderUser *cur = new RerunRecommenderUser(input2);
            sess.getUserMap()->insert({input2, cur});
            works = true;
        }
        if (input3 == "gen") {
            GenreRecommenderUser *cur = new GenreRecommenderUser(input2);
            sess.getUserMap()->insert({input2, cur});
            works = true;
        }

    }
    if (works)
        complete();
    else {
        //error
    }
}

std::string CreateUser::toString() const {
    return "CreateUser";
}



ChangeActiveUser::ChangeActiveUser() : BaseAction (){}

void ChangeActiveUser::act(Session &sess) {
    if (sess.getCounter() == 2) {
        unordered_map<string, User *> *userList = sess.getUserMap();
        unordered_map<string, User *>::const_iterator got = userList->find(sess.getInput2());
        if (sess.getCounter() != 2 | got == userList->end())
            error("User Not Found");
        else {
            sess.setActiveUser(got->second);
            complete();
        }
    } else error("Incorrect command");


}




Watch::Watch() : BaseAction (){}

void Watch::act(Session &sess) {

}

std::string Watch::toString() const {
    return "Watch";
}



PrintActionsLog::PrintActionsLog() : BaseAction (){}

void PrintActionsLog::act(Session &sess) {
    *actionsLog = sess.getActionsLog();
    for (BaseAction *b: *actionsLog) {
        ActionStatus a = b->getStatus();
        string s = "";
        switch (a) {
            case ERROR:
                s.append(b->toString() + " ERROR: " + b->getErrorMsg());
                break;
            case COMPLETED:
                s.append(b->toString() + " COMPLETED");
                break;
            case PENDING:
                s.append(b->toString() + " PENDING");
                break;
        }
        cout << s << endl;
    }
}

std::string PrintActionsLog::toString() const {
    return "PrintActionLog";
}



DeleteUser::DeleteUser(): BaseAction (){}

void DeleteUser::act(Session &sess) {
    if (sess.getCounter()==2&&sess.getInput2()!="default")
    {
        if(sess.getActiveUser()->getName()==sess.getInput2())
            sess.setActiveUser((sess.getUserMap()->find("default"))->second);
        if(sess.containsUser(sess.getInput2())) {
            sess.getUserMap()->erase(sess.getInput2());
            complete();
        }
        else error("User not found");

    }
    else error("Incorrect command");

}




DuplicateUser::DuplicateUser() : BaseAction (){}

void DuplicateUser::act(Session &sess) {
    if(sess.getCounter()!=3||sess.containsUser(sess.getInput2())|!sess.containsUser(sess.getInput3()))
    {
        error("Incorrect command");

    }

    User *todup=sess.getUser(sess.getInput2())->duplactUser(sess.getInput3());
    sess.getUserMap()->insert({todup->getName(),todup});
    complete();
}



PrintWatchHistory::PrintWatchHistory() : BaseAction (){}

void PrintWatchHistory::act(Session &sess) {
    vector<Watchable *> history = sess.getActiveUser()->get_history();
    string str = "Watch history for ";
    str.append(sess.getActiveUser()->getName() + '\n');
    for (Watchable *w : history) {
        str.append(w->getId() + " " + w->toString() + '\n');
    }
    cout << str << endl;

}




PrintContentList::PrintContentList() : BaseAction (){}

void PrintContentList::act(Session &sess) {
    vector<Watchable *> *content = sess.getContent();
    for (Watchable *w : *content) {
        string s = "[";
        string str = w->getId() + " " + w->toString() + " ";
        vector<string> tags = w->getTags();
        for (int i = 0; i < tags.size(); ++i)
            if (i != 0)
                s.append("," + tags[i]);
        s.append("]");
        cout << str + to_string(w->getLength()) + s << endl;
    }
}




Exit::Exit() : BaseAction (){}

void Exit::act(Session &sess) {

}

std::string Exit::toString() const {
    return "Exit";
}



