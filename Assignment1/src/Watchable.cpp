#include "../include/Watchable.h"
#include "../include/Watchable.h"

#include <utility>

using namespace std;

Watchable::Watchable (long _id, int _length, vector<string> _tags):
id(_id), length(_length), tags((_tags)) {}

long Watchable::getId() const {
    return id;
}

std::vector<std::string> Watchable::getTags() const {
    return tags;
}

int Watchable::getLength() const  {
    return length;
}


Watchable::~Watchable() = default;




Episode::Episode( long _id, const string &_seriesName,
                  int _length, int _season, int _episode, const vector<string> &_tags) : Watchable(_id,_length, _tags),
                                                                                         seriesName(_seriesName),season(_season),episode(_episode){}
string Episode::toString() const {
    return seriesName;
}
string Episode::toString2()  {
    string forses="";
    if (season<10)
        forses="0"+season;
    else
        forses=season;
    if(episode<10)
        forses.append("E0"+episode);
    else forses.append("E"+episode);
    vector<string> a=getTags();
    string genres="";
    for (int  i =0; i <a.size(); ++i) {
        if (i != 0)
            genres += ", ";
        genres+=a[i] ;
    }


    const string tostring=to_string(getId())+". "+seriesName+ " "+ forses+ " "+getLength()+" minutes ["+genres+"]";
    return tostring;
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





