
#include "../include/User.h"

using namespace std;

User::User(const std::string &name):name(name) {


}

string User::getName() const {
    return name;
}

std::vector<Watchable *> User::get_history() const {
    return vector<Watchable *>();
}
