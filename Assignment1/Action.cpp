//
// Created by lior on 18/11/2019.
//

#include "../include/Action.h"

ActionStatus BaseAction::getStatus() const {
    return COMPLETED;
}

BaseAction::BaseAction() {

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

std::string PrintActionsLog::toString() const {
    return std::__cxx11::string();
}

void PrintActionsLog::act(Session &sess) {

}

std::string Watch::toString() const {
    return std::__cxx11::string();
}

void Watch::act(Session &sess) {

}

std::string CreateUser::toString() const {
    return std::__cxx11::string();
}

void CreateUser::act(Session &sess) {

}
