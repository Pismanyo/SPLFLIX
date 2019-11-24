#include "../include/Watchable.h"
#include "../include/Watchable.h"

#include <utility>

using namespace std;

Watchable::Watchable (long _id, int _length, vector<string> _tags):
id(_id), length(_length), tags(std::move(_tags)) {}


    Watchable::~Watchable() = default;




Episode::Episode( long _id, const string &_seriesName,
                  int _length, int _season, int _episode, const vector<string> &_tags) : Watchable(_id,_length, _tags),
                                                                                         seriesName(_seriesName),season(_season),episode(_episode){}

string Episode::toString() const {
    return std::__cxx11::string();
}

Watchable *Episode::getNextWatchable(Session &) const {
    return nullptr;
};

Movie::Movie(long _id, const string &_name, int _length, const std::vector<std::string> &_tags) : Watchable(_id,_length, _tags),
                                                                                                  name(_name){}

std::string Movie::toString() const {
    return std::__cxx11::string();
}

Watchable *Movie::getNextWatchable(Session &) const {
    return nullptr;
}





