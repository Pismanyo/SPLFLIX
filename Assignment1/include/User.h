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
    void updateHistory(std::vector<Watchable*>);
    static void sortVec(int,int,std::vector<std::pair<int,std::string>>&);
    virtual User* clone() const =0;
protected:
    std::vector<Watchable*> history;
private:
    const std::string name;
};

class LengthRecommenderUser : public User {
public:
    LengthRecommenderUser(const std::string& name);
    virtual User* duplactUser(const std::string& name )const ;
    virtual Watchable* getRecommendation(Session& s);
    virtual User* clone() const override ;
private:
};

class RerunRecommenderUser : public User {
public:
    virtual User* duplactUser(const std::string& name )const ;
    RerunRecommenderUser(const std::string& name);
    virtual Watchable* getRecommendation(Session& s);
    virtual User* clone() const override ;
private:
    int Reruns;
};

class GenreRecommenderUser : public User {
public:
    GenreRecommenderUser(const std::string& name);
    virtual User* duplactUser(const std::string& name )const ;
    virtual Watchable* getRecommendation(Session& s);
    virtual User* clone() const override ;
private:
};

#endif