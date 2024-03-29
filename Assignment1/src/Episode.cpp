//
// Created by joni on 20/11/2019.
//

#include "../include/Watchable.h"
using namespace std;

Episode::Episode( long _id, const std::string &_seriesName,
                 int _length, int _season, int _episode, const std::vector<std::string> &_tags) : Watchable(_id,_length, _tags),
seriesName(_seriesName),season(_season),episode(_episode){}

std::string Episode::toString() const {
    return std::__cxx11::string();
}

Watchable *Episode::getNextWatchable(Session &) const {
    return nullptr;
};