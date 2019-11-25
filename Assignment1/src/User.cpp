
#include "../include/User.h"
#include "../include/Session.h"
#include "../include/Watchable.h"


using namespace std;


User::User(const std::string &name):name(name) {}
User::User(const User &other):name(other.name) {

    history=other.history;
    for (auto watchable: other.history)
        watchable= nullptr;



   /*
    for (Watchable* watch: other.history)
    {
        this->history.push_back(watch->clone());
    }
    */

}


string User::getName() const {
    return name;
}

std::vector<Watchable *> User::get_history() const {
    return history;
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

RerunRecommenderUser::RerunRecommenderUser(const RerunRecommenderUser &other) : User(other) {
    this->Reruns=other.Reruns;
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

LengthRecommenderUser::LengthRecommenderUser(const LengthRecommenderUser &other) : User(other){}

GenreRecommenderUser::GenreRecommenderUser(const std::string &name) : User(name) {

}

Watchable *GenreRecommenderUser::getRecommendation(Session &s) {
    return nullptr;
}

GenreRecommenderUser::GenreRecommenderUser(const GenreRecommenderUser &other) :User(other) {}
