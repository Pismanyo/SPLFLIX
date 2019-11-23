

#include "../include/Action.h"

ActionStatus BaseAction::getStatus() const {
    return COMPLETED;
}

BaseAction::BaseAction() {
    errorMsg="ERROR!";
    status=PENDING;

}

std::string BaseAction::getErrorMsg() const {
    return std::__cxx11::string();
}

void BaseAction::error(const std::string &errorMsg) {

}

void BaseAction::complete() {

}

std::string Exit::toString() const {
    return std::__cxx11::string();
}

void Exit::act(Session &sess) {

}

