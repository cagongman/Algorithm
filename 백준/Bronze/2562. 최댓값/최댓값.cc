#include <iostream>

int main() {
    int maxNum = 0;
    int maxIndex = 0;
    int num;

    for (int i = 1; i <= 9; ++i) {
        std::cin >> num;

        if (num > maxNum) {
            maxNum = num;
            maxIndex = i;
        }
    }

    std::cout << maxNum << std::endl;
    std::cout << maxIndex << std::endl;

    return 0;
}