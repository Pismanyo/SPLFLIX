
#include <algorithm>
#include "../include/User.h"
#include "../include/Session.h"
#include "../include/Watchable.h"


using namespace std;


User::User(const std::string &name):name(name) {}

void User::copyHistory(const User &other) {
    for (Watchable* watch: other.history)
        this->history.push_back(watch);
}

string User::getName() const {
    return name;
}

std::vector<Watchable *> User::get_history() const {
    return history;
}

void User::addHistory(Watchable *watch) {
    history.push_back(watch);

}

void User::sortVec(int left, int right, std::vector<pair<int,std::string>>& vc) {
    std::vector<pair<int, std::string>> fixedPart;
    for (int i = left; i <= right; ++i) {
        fixedPart.push_back(vc.at(i));
    }
    reverse(fixedPart.begin(), fixedPart.end());

    for (int i = left; i <= right; ++i) {
        vc.at(i).second = fixedPart.at(i - left).second;
    }
}

RerunRecommenderUser::RerunRecommenderUser(const string &name) : User(name) {
    Reruns=0;

}

Watchable *RerunRecommenderUser::getRecommendation(Session &s) {
    Watchable *cur=nullptr;
    vector<Watchable*> his=this->get_history();
    if(his.size()!=0)
    {
        cur= his[Reruns%(his.size())];
    }

    Reruns++;
    return cur;
}

User *RerunRecommenderUser::duplactUser(const std::string &name) const{
    RerunRecommenderUser *user=new RerunRecommenderUser(name);
    user->copyHistory(*this);
    user->Reruns=this->Reruns;
    return user;
}

User *RerunRecommenderUser::clone() const {
    return new RerunRecommenderUser(*this);
}


LengthRecommenderUser::LengthRecommenderUser(const std::string &name) : User(name) {}

Watchable *LengthRecommenderUser::getRecommendation(Session &s) {
    vector<Watchable *> *content = s.getContent();
    vector<Watchable *> his = this->get_history();
    Watchable *cur = nullptr;
    int sum = 0;
    for (Watchable *w : his)
        sum += w->getLength();

    float average = sum / his.size();
    float closest = -1;

    for (Watchable *c : *content) {
        if (closest == -1) {
            bool contains = false;
            for (int i=0;i<his.size()&&(!contains);++i ){
                if (his[i]->getId() == c->getId())
                    contains = true;
            }
            if (!contains) {
                cur = c;
                closest = abs(cur->getLength() - average);
            }
        }

        else {
            if (closest > abs(c->getLength() - average)) {
                bool contains = false;
                for (int i=0;i<his.size()&&(!contains);++i ){
                    if (his[i]->getId() == c->getId())
                        contains = true;
                }
                if (!contains) {
                    cur = c;
                    closest = abs(cur->getLength() - average);
                }

            }

        }
    return cur;

    }
    return cur;
}

User *LengthRecommenderUser::duplactUser(const std::string &name) const{
    LengthRecommenderUser *user=new LengthRecommenderUser(name);
    user->copyHistory(*this);
    return user;
}

User *LengthRecommenderUser::clone() const {
    return new LengthRecommenderUser(*this);
}

User *GenreRecommenderUser::duplactUser(const std::string &name) const{
    GenreRecommenderUser *user=new GenreRecommenderUser(name);
    user->copyHistory(*this);
    return user;
}

GenreRecommenderUser::GenreRecommenderUser(const std::string &name) : User(name) {}

Watchable *GenreRecommenderUser::getRecommendation(Session &s) {
    Watchable *cur = nullptr;
    vector<Watchable *> *content = s.getContent();
    vector<Watchable *> his = this->get_history();
    vector<pair<int, string>> vc;
    for (Watchable *w: his) {
        for (string str: w->getTags()) {
            bool tagExists = false;
            for (pair<int, string> p : vc) {
                if (p.second.compare(str) == 0) {
                    ++p.first;
                    tagExists = true;
                }
            }
            if (!tagExists)
                vc.push_back(make_pair(1, str));
        }
    }
    sort(vc.begin(), vc.end());
    reverse(vc.begin(), vc.end());

    if (!vc.empty()) {
        int x = vc.at(0).first;
        string st = vc.at(0).second;
        int count = 0;
        for (int t = 1; t < vc.size(); ++t) {
            if (vc.at(t).first == x)
                ++count;
            else {
                if (count > 0) {
                    sortVec(t - 1 - count, t - 1, vc);
                }
                x = vc.at(t).first;
                st = vc.at(t).second;
                count = 0;
            }
        }
        if(count>0)
            sortVec(vc.size()-1-count,vc.size()-1,vc);
    }



        string recTag;

        bool found = false;
        for (int i = 0; !found && i < vc.size(); ++i) {
            recTag = vc.at(i).second;
            for (int j = 0; !found && j < content->size(); ++j) {
                vector<string> tagVec = content->at(j)->getTags();
                for (int k = 0; !found && k < tagVec.size(); ++k) {
                    if (tagVec.at(k).compare(recTag) == 0) {
                        bool goodTag = true;
                        for (int t = 0; t < his.size(); ++t) {
                            if (his.at(t)->getId() == content->at(j)->getId())
                                goodTag = false;
                        }
                        if (goodTag) {
                            found = true;
                            cur = content->at(j);
                        }

                    }
                }
            }
        }
        return cur;
    }

User *GenreRecommenderUser::clone() const {
    return new GenreRecommenderUser(*this);
}




