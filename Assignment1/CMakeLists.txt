cmake_minimum_required(VERSION 3.15)
project(Assignment1)

set(CMAKE_CXX_STANDARD 11)
set(SOURCE_FILES  Session.cpp, Session.h, User.cpp, User.h, Watchable.cpp, nclude/Watchable.h)
add_executable(Assignment1 src/Main.cpp src/User.cpp include/Watchable.h src/Session.cpp src/Watchable.cpp src/Action.cpp)