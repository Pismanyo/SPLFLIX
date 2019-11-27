
#include "../include/User.h"
#include "../include/Session.h"
#include "../include/Watchable.h"


using namespace std;


User::User(const std::string &name):name(name) {}
void User::copyHistory(const User &other) {
    for (Watchable* watch: other.history)
    {
        this->history.push_back(watch->clone());
    }


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


RerunRecommenderUser::RerunRecommenderUser(const string &name) : User(name) {
    Reruns=0;

}

Watchable *RerunRecommenderUser::getRecommendation(Session &s) {
    Watchable *cur=nullptr;
    vector<Watchable*> his=this->get_history();
    //cout<< 1%1<<endl;
    if(his.size()!=0)
    {
        //cout<<(Reruns%(his.size())<<endl;
        cur= his[Reruns%(his.size())];
    }
    // Watchable *cur= his[Reruns%(his.size()-1)];
    //  cout<<Reruns%(his.size()-1)<<endl;
    Reruns++;
    return cur;
}

User *RerunRecommenderUser::duplactUser(const std::string &name) const{
    RerunRecommenderUser *user=new RerunRecommenderUser(name);
    user->copyHistory(*this);
    user->Reruns=this->Reruns;
    return user;
}


LengthRecommenderUser::LengthRecommenderUser(const std::string &name) : User(name) {

}

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

    }
    //if (closest==-1) //then all the epsoides and movies have been played already
    return cur;
}

User *LengthRecommenderUser::duplactUser(const std::string &name) const{
    LengthRecommenderUser *user=new LengthRecommenderUser(name);
    user->copyHistory(*this);
    return user;
}

User *GenreRecommenderUser::duplactUser(const std::string &name) const{
    GenreRecommenderUser *user=new GenreRecommenderUser(name);
    user->copyHistory(*this);
    return user;
}

GenreRecommenderUser::GenreRecommenderUser(const std::string &name) : User(name) {

}

Watchable *GenreRecommenderUser::getRecommendation(Session &s) {
    Watchable* cur = nullptr;
    vector<Watchable*> *content=s.getContent();
    vector<Watchable*> his=this->get_history();
    std::unordered_map<std::string,int> genreMap;
    string recTag;
    int tagCount=0;

    for(Watchable* w: his){
        std::vector<std::string> str = w->getTags();
        for(string s: str){
            if(genreMap.count(s)==0)
                genreMap.insert({s,1});
            else
                genreMap.at(s)++;
        }
    }

    for(Watchable* w: his){
        std::vector<std::string> str = w->getTags();
        for(string s: str) {
            if (genreMap.at(s) > tagCount) {
                tagCount = genreMap.at(s);
                recTag = s;
            } else if (genreMap.at(s) == tagCount)
                if (s.compare(recTag) == -1)
                    recTag = s;
        }
    }

    for(Watchable* w: *content) {
        bool f=true;
        std::vector<std::string> str = w->getTags();
        for (string s: str)
            if (s.compare(recTag) == 0)
                for (Watchable *w2: his)
                    if (w2->getId() == w->getId())
                        f = false;
        if (f) {
            cur = w;
            break;
        }
    }
    return cur;
}


