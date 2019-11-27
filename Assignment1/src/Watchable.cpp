#include "../include/Watchable.h"
#include "../include/Session.h"
#include "../include/User.h"

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
    string forses="";
    if (season<10)
        forses.append("0"+to_string(season));
    else
        forses.append(to_string(season));
    if(episode<10)
        forses.append("E0"+to_string(episode));
    else forses.append("E"+to_string(episode));

    return seriesName+" S"+forses;
}
string Episode::toStringNextEpsoide() const {
    string forses="";
    if (season<10)
        forses.append("0"+to_string(season));
    else
        forses.append(to_string(season));
    if((episode+1)<10)
        forses.append("E0"+to_string(episode+1));
    else forses.append("E"+to_string(episode+1));

    return seriesName+" S"+forses;
}
string Episode::toStringNextSesson() const {
    string forses="";
    if (season+1<10)
        forses.append("0"+to_string(season+1));
    else
        forses.append(to_string(season+1));
     forses.append("E01");

    return seriesName+" S"+forses;
}
/*
string Episode::toString2()  {
    string forses="";
    if (season<10)
        forses.append("0"+to_string(season));
    else
        forses.append(to_string(season));
    if(episode<10)
        forses.append("E0"+to_string(episode));
    else forses.append("E"+to_string(episode));
    vector<string> a=getTags();
    string genres="";
    for (int  i =0; i <a.size(); ++i) {
        if (i != 0)
            genres.append(", ");
        genres.append(a[i]);
    }


    const string tostring=to_string(getId())+". "+seriesName+ " "+ forses+ " "+to_string(getLength())+" minutes ["+genres+"]";
    return tostring;
}
*/
Watchable *Episode::getNextWatchable(Session &a) const {
    vector<Watchable*> *content=a.getContent();
    for (int j=0;j<content->size();++j)
    {
        if ((*content)[j]->toString()==this->toStringNextEpsoide())
            return (*content)[j];
    }
    for (int j=0;j<content->size();++j)
    {
         if((*content)[j]->toString()==this->toStringNextSesson())
             return (*content)[j];
    }

    return (*(a.getActiveUser())).getRecommendation(a);
}

Watchable *Episode::clone()const  {
    return new Episode(*this);
};

Movie::Movie(long _id, const string &_name, int _length, const std::vector<std::string> &_tags) : Watchable(_id,_length, _tags),
                                                                                                  name(_name){}

std::string Movie::toString() const {
    return name;
}

Watchable *Movie::getNextWatchable(Session &a) const {
    return (*(a.getActiveUser())).getRecommendation(a);
}

Watchable *Movie::clone() const {
    return new Movie(*this);
}





