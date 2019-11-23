//
// Created by joni on 20/11/2019.
//


#include "../include/Watchable.h"
using namespace std;

Movie::Movie(long _id, const string &_name, int _length, const std::vector<std::string> &_tags) : Watchable(_id,_length, _tags),
name(_name){}

std::string Movie::toString() const {
    return std::__cxx11::string();
}

Watchable *Movie::getNextWatchable(Session &) const {
    return nullptr;
}
