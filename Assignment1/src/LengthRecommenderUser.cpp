//
// Created by lior on 22/11/2019.
//

#include "../include/User.h"

LengthRecommenderUser::LengthRecommenderUser(const std::string &name) : User(name) {

}

Watchable *LengthRecommenderUser::getRecommendation(Session &s) {
    return nullptr;
}
