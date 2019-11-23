#include "../include/Watchable.h"
#include "../include/Watchable.h"

#include <utility>

using namespace std;

Watchable::Watchable (long _id, int _length, vector<string> _tags):
id(_id), length(_length), tags(std::move(_tags)) {}


    Watchable::~Watchable() = default;

;


