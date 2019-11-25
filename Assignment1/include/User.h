#ifndef USER_H_
#define USER_H_

#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
class Watchable;
class Session;

class User{
public:
    User(const std::string& name);
    void copyHistory(const User &other);
    virtual Watchable* getRecommendation(Session& s) = 0;
    std::string getName() const;
    virtual User* duplactUser(const std::string& name )const=0;
    std::vector<Watchable*> get_history() const;
    void addHistory(Watchable* watch);
protected:
    std::vector<Watchable*> history;
private:
    const std::string name;
};


class LengthRecommenderUser : public User {
public:
    LengthRecommenderUser(const std::string& name);
  //  LengthRecommenderUser(const LengthRecommenderUser& other);
    virtual User* duplactUser(const std::string& name )const ;
    virtual Watchable* getRecommendation(Session& s);
private:
};

class RerunRecommenderUser : public User {
public:
   // RerunRecommenderUser(const RerunRecommenderUser& other);
     virtual User* duplactUser(const std::string& name )const ;
    RerunRecommenderUser(const std::string& name);
    virtual Watchable* getRecommendation(Session& s);
private:
    int Reruns;
};

class GenreRecommenderUser : public User {
public:
    GenreRecommenderUser(const std::string& name);
    virtual User* duplactUser(const std::string& name )const ;
    virtual Watchable* getRecommendation(Session& s);
private:
};

#endif
