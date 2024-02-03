#include <iostream>

int countZero[41];
int countOne[41];

void fibonacci(int n) {
    countZero[0] = 1;
    countOne[0] = 0;
    countZero[1] = 0;
    countOne[1] = 1;

    for (int i = 2; i <= n; ++i) {
        countZero[i] = countZero[i - 1] + countZero[i - 2];
        countOne[i] = countOne[i - 1] + countOne[i - 2];
    }
}

int main() {
    int T, N;
	int max;
    std::cin >> T;
	
	fibonacci(40);
	
    while (T--) {
        std::cin >> N;  // N 입력
        std::cout << countZero[N] << ' ' << countOne[N] << std::endl;  // 0과 1이 출력되는 횟수 출력
    }

    return 0;
}