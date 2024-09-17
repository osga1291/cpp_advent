#ifndef worker_H
#define worker_H



#include <cmath>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

class Worker{
    private:
        std::vector<std::string> data;
    public:
        void readFile(const std::string& data);
        int dayOne();
        void conversion();
        int conversionDice();
        int conversionDice2();
        std::vector<std::vector<char>> conversion2();
        int dayThree(std::vector<std::vector<char>>& matrix);
        
};

std::vector<std::string> split(std::string s, std::string delimiter);
int helper(int i, int j, std::string totalNum, bool valid, std::vector<std::vector<char>>& matrix);
bool innerhelper(int i, int j,std::vector<std::vector<char>>& matrix);

#endif