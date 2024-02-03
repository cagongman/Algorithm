#include <iostream>
#include <string>

int main() {
    int A, B, C;
    std::cin >> A >> B >> C;

    int result = A * B * C;
    std::string strResult = std::to_string(result);

    int freq[10] = {0};

    for (char digit : strResult) {
        freq[digit - '0']++;
    }

    for (int i = 0; i < 10; ++i) {
        std::cout << freq[i] << std::endl;
    }

    return 0;
}