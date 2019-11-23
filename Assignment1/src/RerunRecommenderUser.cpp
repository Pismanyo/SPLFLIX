//
// Created by lior on 22/11/2019.
//

#include "../include/User.h"

RerunRecommenderUser::RerunRecommenderUser(const std::string &name) : User(name) {

}

Watchable *RerunRecommenderUser::getRecommendation(Session &s) {
    return nullptr;
}
