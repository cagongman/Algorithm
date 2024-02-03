#include <iostream>
#include <string>

int main() {
    int T;
    std::cin >> T;

    while (T--) {
        int R;
        std::string S, P;
        std::cin >> R >> S;

        for (char c : S) {
            for (int i = 0; i < R; ++i) {
                P += c;
            }
        }

        std::cout << P << std::endl;
    }

    return 0;
}