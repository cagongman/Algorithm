#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size(), 0);
    stack<int> s;

    for (int i = 0; i < prices.size(); i++) {
        // 스택이 비어있지 않고, 현재 가격이 스택의 탑 가격보다 낮을 때
        while (!s.empty() && prices[s.top()] > prices[i]) {
            int top = s.top();
            s.pop();
            answer[top] = i - top; // 떨어진 시점 계산
        }
        s.push(i); // 현재 인덱스를 스택에 추가
    }

    // 끝까지 가격이 떨어지지 않은 경우 처리
    while (!s.empty()) {
        int top = s.top();
        s.pop();
        answer[top] = prices.size() - top - 1;
    }

    return answer;
}