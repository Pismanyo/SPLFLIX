
#include "../include/User.h"
#include "../include/Session.h"
#include "../include/Watchable.h"


using namespace std;


User::User(const std::string &name):name(name) {


}

string User::getName() const {
    return name;
}

std::vector<Watchable *> User::get_history() const {
    return history;
}
RerunRecommenderUser::RerunRecommenderUser(const string &name) : User(name) {

}

Watchable *RerunRecommenderUser::getRecommendation(Session &s) {
    return nullptr;
}
LengthRecommenderUser::LengthRecommenderUser(const std::string &name) : User(name) {

}

Watchable *LengthRecommenderUser::getRecommendation(Session &s) {
    vector<Watchable*> *con=s.getContent();
    vector<Watchable*> his=this->get_history();
    int sum=0;
    for (int i=0;i<his.size();++i)
    {
       sum+= his[i]->getLength();
    }




    return nullptr;
}
GenreRecommenderUser::GenreRecommenderUser(const std::string &name) : User(name) {

}

Watchable *GenreRecommenderUser::getRecommendation(Session &s) {
    return nullptr;
}
