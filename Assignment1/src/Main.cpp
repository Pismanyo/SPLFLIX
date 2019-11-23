#include <iostream>
#include "../include/Session.h"

using namespace std;


int main(int argc, char** argv){
	if(argc!=2)
	{
		cout << "usage splflix input_file" << endl;
		//return 0;
	}
	//Session s(argv[1]);
   // Session s("/home/joni/Downloads/config1.json");
    Session s("/home/lior/Documents/Assignment 1/config/config1.json");
    //std::cout << "what are yiu sa"<<endl;
	s.start();
	return 0;
}
