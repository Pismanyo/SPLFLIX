
#include "../include/Session.h"
#include "../include/json.hpp"
#include <fstream>
using json = nlohmann::json ;
using namespace std;

Session::Session(const std::string &configFilePath) {
ifstream file(configFilePath);
json j;
string line;
string temp;
file >> j;
cout << j.at("tv_series") << endl;



}

Session::~Session() {
}

void Session::start() {

}
