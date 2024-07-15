#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size(), 0);
    stack<int> s;
    int index;
    
    for(int i = 0; i < prices.size() - 1; i++)
    {
        if(s.empty())
        {
            s.push(i);
            continue;
        }
    
        index = s.top();
        
        // 주식 값이 떨어졌을때
        if(prices[index] > prices[i])
        {
            while(!s.empty())
            {
                answer[index] = i - index;
                s.pop();
                
                if(!s.empty())
                {
                    index = s.top();
                
                    if(prices[index] <= prices[i])
                        break;
                }
            }
        }
        
        s.push(i);
    }
    
    while(!s.empty())
    {
        answer[s.top()] = prices.size() - s.top() - 1;
        s.pop();
    }
        
    
    return answer;
}