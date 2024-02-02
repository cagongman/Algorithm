#include <iostream>
#include <sstream>
#include <string>

int main() {
    std::string line;
    std::getline(std::cin, line);
    
    std::istringstream iss(line);
    std::string word;
    int count = 0;
    
    while (iss >> word) {
        count++;
    }
    
    std::cout << count;
    
    return 0;
}