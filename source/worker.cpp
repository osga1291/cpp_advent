#include "worker.h"


void Worker::readFile(const std::string& file)
{

    std::ifstream myFile(file);

    std::string line;
    double val;

    std::vector<std::string> currLine;
    if (!myFile.is_open())
        throw std::runtime_error("Could not open");

    while (std::getline(myFile, line)) {
        

        currLine.emplace_back(line);
        
    }

    myFile.close();
    data = currLine;
    std::cout<< "Reading of data complete.\n";
}

int Worker::dayOne(){
    int sum = 0;
    for (std::string i: data){
        char one = 'a';
        char two = 'b';
        for(const char j: i){
            if(isdigit(j)){
                two = j;
                if (!isdigit(one)){
                    one = j;
            }
        }
        }
        std::string num;
        std::cout << (num+one+two) << std::endl;
        sum += stoi(num + one + two);
        
    }

    return sum;
}

void Worker::conversion(){
    
    std::unordered_map<std::string, std::string> map {
        {"one", "1"}, 
        {"two", "2"},
        {"three", "3"},
        {"four", "4"},
        {"five", "5"},
        {"six", "6"},
        {"seven", "7"},
        {"eight", "8"},
        {"nine","9"}  
    };

    std::vector<std::string> conv;

    for (auto const& p : map){
        
        for (std::string& word: data){
            int l_pos = word.find(p.first);
            int r_pos = word.rfind(p.first);
            if (l_pos != -1){
                if (l_pos != r_pos){
                    word.insert(r_pos +1, p.second);
                }
                word.insert(l_pos + 1, p.second);
            }
        }   

    }

}

int Worker::conversionDice(){
    std::unordered_map<std::string, int>map {
        {"blue", 14},
        {"red", 12},
        {"green", 13}
    };
    int count = 0;
    for (std::string word: data){
        auto firstSplit = split(word, ": ");
        auto idSplit = split(firstSplit[0], " ");

        auto secondSplit = split(firstSplit[1], "; ");
        bool invalidGame = false;
        for (std::string j : secondSplit){
            if (invalidGame){
                break;
            }
            auto thirdSplit = split(j, ", ");
            for (std::string z: thirdSplit){
                auto fourthSplit = split(z, " ");
                if (map.find(fourthSplit[1]) != map.end()){
                    if (std::stoi(fourthSplit[0]) > map[fourthSplit[1]]){
                        invalidGame = true;
                        break;
                    }
                }

            }  
        }
        
        std::cout << word << std::endl;
        if (invalidGame == false){
            count = count + std::stoi(idSplit[1]);  
            std::cout << idSplit[1] << std::endl;
        }   
    }

    return count;

}

int Worker::conversionDice2(){
    
    int count = 0;
    for (std::string word: data){
        std::unordered_map<std::string, int>map {
        {"blue", 10000},
        {"red", 10000},
        {"green", 100000}
    };
        auto firstSplit = split(word, ": ");
        auto idSplit = split(firstSplit[0], " ");

        auto secondSplit = split(firstSplit[1], "; ");
        for (std::string j : secondSplit){
           
            auto thirdSplit = split(j, ", ");
            for (std::string z: thirdSplit){
                auto fourthSplit = split(z, " ");
                map[fourthSplit[1]] = std::min(std::stoi(fourthSplit[0]), map[fourthSplit[1]]);

            }  
        }
        
        std::cout << word << std::endl;
        std::cout << map["green"] << std::endl << map["red"] << std::endl << map["blue"] << std::endl;
        count += (map["green"] * map["red"] * map["blue"]);
    }

    return count;

}

std::vector<std::string> split(std::string s, std::string delimiter) {
    std::vector<std::string> tokens;
    size_t pos = 0;
    std::string token;
    while ((pos = s.find(delimiter)) != std::string::npos) {
        token = s.substr(0, pos);
        s.erase(0, pos + delimiter.length());
        if (delimiter == delimiter){
            tokens.push_back(token);
        }
    }
    tokens.push_back(s);

    return tokens;
};


std::vector<std::vector<char>> Worker::conversion2(){
    std::vector<std::vector<char>> matrix;
    for (std::string word: data){
        std::vector<char> row;
        for (auto i : word){
            row.emplace_back(i);
        }
        matrix.emplace_back(row);
}
    return matrix;
}

int dayThree(std::vector<std::vector<char>>& matrix){
    int total = 0;
    for (int i = 0; i < matrix.size() - 1; i++ ){
        for (int j = 0; j < matrix[i].size() - 1; j++){
            if (isdigit(matrix[i][j])){
                total += helper(i, j , "", false, matrix);
            }
        }
    }
    return total;
}

int helper(int i, int j, std::string totalNum, bool valid, std::vector<std::vector<char>>& matrix){
    if (i > matrix.size() - 1 || !isdigit(matrix[i][j])){
        if (!valid){
            return 0;
        }
        return std::stoi(totalNum);
    }
  
    if (!valid){
        valid = innerhelper(i-1, j, matrix) || innerhelper(i + 1, j, matrix) || innerhelper(i, j-1, matrix) || innerhelper(i, j+1, matrix);
    }
        totalNum += matrix[i][j];
        matrix[i][j] = '.'; 
    
    return helper(i + 1, j, totalNum, valid, matrix);
}

bool innerhelper(int i, int j,std::vector<std::vector<char>>& matrix){

    if (i > matrix.size() - 1 || i < 0){
        return false;
    }
    else if (j > matrix[i].size() - 1 || j < 0){
        return false;
    }

    else if (isdigit(matrix[i][j]) || matrix[i][j] == '.'){
        return false;
    }

    return true;
    

    



}
