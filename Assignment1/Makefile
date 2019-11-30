# define makefile variables
CC = g++
CFLAGS  = -g -Wall -Weffc++ -std=c++11
LFLAGS  = -L/usr/lib


# Executable "SPLFLIX" depends on the files hello.o and run.o.
SPLFLIX: bin/Session.o bin/User.o bin/Main.o bin/Action.o bin/Watchable.o
	@echo 'Building target: hello by Invoking C++ Linker'
	$(CC) -o bin/SPLFLIX bin/Session.o bin/User.o bin/Main.o bin/Action.o bin/Watchable.o $(LFLAGS)

# Object code (*.o file) depends on the source and header files
bin/Session.o: src/Session.cpp include/Session.h include/json.hpp include/Watchable.h include/User.h
	$(CC) $(CFLAGS) -c -Iinclude -o bin/Session.o src/Session.cpp

# Depends on the source and header files 
bin/Main.o: src/Main.cpp  include/Session.h
	$(CC) $(CFLAGS) -c -Iinclude -o bin/Main.o src/Main.cpp

bin/User.o: src/User.cpp  include/Session.h include/User.h include/Watchable.h
	$(CC) $(CFLAGS) -c -Iinclude -o bin/User.o src/User.cpp

bin/Watchable.o: src/Watchable.cpp  include/Session.h include/User.h include/Watchable.h
	$(CC) $(CFLAGS) -c -Iinclude -o bin/Watchable.o src/Watchable.cpp

bin/Action.o: src/Action.cpp  include/Session.h include/User.h include/Watchable.h include/Action.h
	$(CC) $(CFLAGS) -c -Iinclude -o bin/Action.o src/Action.cpp

#Clean the build directory
clean: 
	rm -f bin/*
