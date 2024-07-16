#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<int> order) {
    int answer = 0;
    stack<int> s;
    
    for(int i = 1; i <= order.size(); i++)
    {
        // 컨테이너 벨트에 온게 딱 실어야할 박스일 때
        if(i == order[answer])
        {
            // 실은 박스 개수 추가
            answer++;
            
            // 보관 벨트의 박스 확인
            while(!s.empty())
            {
                // 보관 벨트의 마지막 상자를 실어야할 경우
                if(s.top() == order[answer])
                {
                    answer++;
                    s.pop();
                }
                else
                    break;
            }
        }
        else
            s.push(i);
    }
    
    return answer;
}