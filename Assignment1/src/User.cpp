
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
    if(his.size()!=0)
    Watchable *cur= his[Reruns%(his.size()-1)];

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
    vector<Watchable*> *content=s.getContent();
    vector<Watchable*> his=this->get_history();
    int sum=0;
    for (int i=0;i<his.size();++i)
    {
       sum+= his[i]->getLength();

    }
    float average=sum/his.size();

    Watchable *cur= nullptr;
    float closest=-1;

   for (int j=0;j<content->size();++j)
   {
       if(closest==-1) {

           bool contians = false;
           for (int i = 0; i < his.size(); ++i) {
               if (his[i]->getId() == (*content)[j]->getId()) {
                   contians = true;
               }
               if(!contians)
               {
                   cur=(*content)[j];
                   closest=abs((*cur).getLength()-average);
               }
           }
       }
       else{
           if(closest>abs((*content)[j]->getLength()-average))
           {
               bool contians = false;
               for (int i = 0; i < his.size(); ++i)
               {
                   if (his[i]->getId() == (*content)[j]->getId()) {
                       contians = true;
                   }
                   if(!contians)
                   {
                       cur=(*content)[j];
                       closest=abs((*cur).getLength()-average);
                   }

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


GenreRecommenderUser::GenreRecommenderUser(const std::string &name) : User(name) {

}

Watchable *GenreRecommenderUser::getRecommendation(Session &s) {
    return nullptr;
}

User *GenreRecommenderUser::duplactUser(const std::string &name) const{
    GenreRecommenderUser *user=new GenreRecommenderUser(name);
    user->copyHistory(*this);
    return user;
}

