#include <iostream>
#include <string>
#include <map>
#include <cctype>

int main() {
    std::string word;
    std::cin >> word;

    std::map<char, int> freq;
    int maxFreq = 0;
    char maxChar = '?';

    for (char c : word) {
        char upperC = std::toupper(c); 
        freq[upperC]++;

        if (freq[upperC] > maxFreq) {
            maxFreq = freq[upperC];
            maxChar = upperC;
        }
    }


    int countMax = 0;
    for (auto const &pair : freq) {
        if (pair.second == maxFreq) {
            countMax++;
        }
    }

    if (countMax > 1) {  
        std::cout << '?';
    } else {
        std::cout << maxChar;
    }

    return 0;
}
