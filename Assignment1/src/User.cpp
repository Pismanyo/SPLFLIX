
#include "../include/User.h"

using namespace std;

User::User(const std::string &name):name(name) {


}

string User::getName() const {
    return name;
}

std::vector<Watchable *> User::get_history() const {
    return vector<Watchable *>();
}
RerunRecommenderUser::RerunRecommenderUser(const string &name) : User(name) {

}

Watchable *RerunRecommenderUser::getRecommendation(Session &s) {
    return nullptr;
}
LengthRecommenderUser::LengthRecommenderUser(const std::string &name) : User(name) {

}

Watchable *LengthRecommenderUser::getRecommendation(Session &s) {
    return nullptr;
}
GenreRecommenderUser::GenreRecommenderUser(const std::string &name) : User(name) {

}

Watchable *GenreRecommenderUser::getRecommendation(Session &s) {
    return nullptr;
}
