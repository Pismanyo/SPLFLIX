//
// Created by lior on 18/11/2019.
//

#include "../include/User.h"


std::vector<Watchable *> User::get_history() const {
    return std::vector<Watchable *>();
}

User::User(const std::string &name) {

}

std::string User::getName() const {
    return std::__cxx11::string();
}

Watchable *LengthRecommenderUser::getRecommendation(Session &s) {
    return nullptr;
}

LengthRecommenderUser::LengthRecommenderUser(const std::string &name) : User(name) {

}

Watchable *RerunRecommenderUser::getRecommendation(Session &s) {
    return nullptr;
}

RerunRecommenderUser::RerunRecommenderUser(const std::string &name) : User(name) {

}

Watchable *GenreRecommenderUser::getRecommendation(Session &s) {
    return nullptr;
}

GenreRecommenderUser::GenreRecommenderUser(const std::string &name) : User(name) {

}
