#include <iostream>
#include <algorithm>
#include <string>

int main() {
    std::string num1, num2;
    
    // 두 수를 문자열로 입력받음
    std::cin >> num1 >> num2;
    
    // 문자열을 뒤집음
    std::reverse(num1.begin(), num1.end());
    std::reverse(num2.begin(), num2.end());
    
    // 문자열로 표현된 두 수를 비교
    if (num1 > num2) {
        std::cout << num1;
    } else {
        std::cout << num2;
    }
    
    return 0;
}