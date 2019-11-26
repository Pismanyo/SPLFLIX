

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
    //cout<<errorMsg<<endl;
}

void BaseAction::complete() {
    status = COMPLETED;


}

std::string BaseAction::getErrorMessage() const {
    return this->getErrorMsg();
}


CreateUser::CreateUser() : BaseAction (){}

void CreateUser::act(Session &sess) {
    string input2 = sess.getInput2();
    string input3 = sess.getInput3();
    if (sess.getCounter() == 3 && sess.getUserMap()->find(input2) == sess.getUserMap()->end()) {
        if (input3 == "len") {
            LengthRecommenderUser *cur = new LengthRecommenderUser(input2);
            sess.getUserMap()->insert({input2, cur});
            complete();
        }
       else  if (input3 == "rer") {
            RerunRecommenderUser *cur = new RerunRecommenderUser(input2);
            sess.getUserMap()->insert({input2, cur});
            complete();
        }
        else if (input3 == "gen") {
            GenreRecommenderUser *cur = new GenreRecommenderUser(input2);
            sess.getUserMap()->insert({input2, cur});
            complete();
        }
        else error("Incorrect input");

    }
    else error("Incorrect input");

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

std::string ChangeActiveUser::toString() const {
    return "ChangeActiveUser";
}


Watch::Watch() : BaseAction (){}

void Watch::act(Session &sess) {
    Watchable* watch= nullptr;
    bool errorfound=false;
    if (!sess.getAgain())
    {
        if (sess.getCounter()==2&sess.is_number(sess.getInput2()))
        {
            int id=stoi(sess.getInput2());
            bool found=false;
            for(auto it = sess.getContent()->begin(); it != sess.getContent()->end()|found; ++it) {
                if ((*it)->getId() == id) {
                    watch=(*it);
                }
            }

        }
        else
        {
            error("Invalid input");
            errorfound=true;

        }
    }
    else {
        watch=sess.getRecommended();
    }
    if(!errorfound) {
        cout << "Watching " + watch->toString() << endl;
        sess.getActiveUser()->addHistory(watch);
        complete();
        sess.setRecommended((watch)->getNextWatchable(sess));
        cout << "We recommend watching " + sess.getRecommended()->toString() + ", continue watching? [y/n]" << endl;
        string anwer;
        getline(cin, anwer);
        if (anwer == "y") {
            sess.setAgain(true);
        } else
            sess.setAgain(false);
    }

}

std::string Watch::toString() const {
    return "Watch";
}



PrintActionsLog::PrintActionsLog() : BaseAction (){}

void PrintActionsLog::act(Session &sess) {
    if (sess.getCounter() != 1)
        error("Incorrect input");
    else {

        std::vector<BaseAction *> *actionsLog = sess.getActionsLog();
        for (BaseAction *b: *actionsLog)
        {
            ActionStatus a = b->getStatus();
            string s = "";
            switch (a)
            {
                case ERROR:
                    s.append(b->toString() + " ERROR: " + b->getErrorMessage());
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
        complete();
    }
}

std::string PrintActionsLog::toString() const {
    return "PrintActionsLog";
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

std::string DeleteUser::toString() const {
    return "DeleteUser";
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

std::string DuplicateUser::toString() const {
    return "DuplicateUser";
}


PrintWatchHistory::PrintWatchHistory() : BaseAction (){}

void PrintWatchHistory::act(Session &sess) {
    if(sess.getCounter()!=1)
        error("Incorrect input");
    else {
        int historyID=0;
        vector<Watchable *> history = sess.getActiveUser()->get_history();
        string str = "Watch history for ";
        str.append(sess.getActiveUser()->getName() + '\n');
        for (Watchable *w : history) {
            str.append(to_string(++historyID) + ". " + w->toString() + '\n');
        }
        cout << str << endl;
        complete();
    }
}

std::string PrintWatchHistory::toString() const {
    return "PrintWatchHistory";
}


PrintContentList::PrintContentList() : BaseAction (){}

void PrintContentList::act(Session &sess) {
    if(sess.getCounter()!=1)
    {
        error("Incorrect input");
    }
    else {
        vector<Watchable *> *content = sess.getContent();
        for (Watchable *w : *content) {
            string s = "[";
            string str = to_string(w->getId()) + ". " + w->toString() + " " + to_string(w->getLength()) + " minutes";
            vector<string> tags = w->getTags();
            for (int i = 0; i < tags.size(); ++i) {
                if (i != 0)
                    s.append(",");
                s.append(tags[i]);
            }
            s.append("]");
            str.append(+" " + s);
            cout << str << endl;
        }
        complete();
    }
}

std::string PrintContentList::toString() const {
    return "PrintContentList";
}


Exit::Exit() : BaseAction (){}

void Exit::act(Session &sess) {
    if(sess.getCounter()==1) {
        sess.setRun(false);
        complete();
    }
    else error("invaild input");

}

std::string Exit::toString() const {
    return "Exit";
}



