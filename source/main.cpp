#include <cstdlib>
#include <iomanip>
#include <iostream>
#include "worker.h"
int main(int argc, char *argv[])
{
    
    Worker x = Worker();
    x.readFile("/Users/oscargandara/cpp_practice/input3.txt");
    std::vector<std::vector<char>> y  = x.conversion2();
    int z = x.dayThree(y);


    //int y = x.dayOne();
    return 1;
}