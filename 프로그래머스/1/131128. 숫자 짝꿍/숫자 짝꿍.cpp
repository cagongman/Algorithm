#include <string>
#include <vector>

using namespace std;

string solution(string X, string Y) {
    std::vector<int> countX(10, 0), countY(10, 0);
    
    // X와 Y의 각 숫자 빈도수 계산
    for (char ch : X) countX[ch - '0']++;
    for (char ch : Y) countY[ch - '0']++;

    // 짝꿍 숫자를 구성
    std::string result = "";
    for (int digit = 9; digit >= 0; digit--) {
        int commonCount = std::min(countX[digit], countY[digit]);
        result.append(commonCount, '0' + digit);
    }

    // 결과 확인
    if (result.empty())
        return "-1";
    if (result[0] == '0')
        return "0";  // 결과가 0으로만 구성되어 있다면, "0" 반환

    return result;
}