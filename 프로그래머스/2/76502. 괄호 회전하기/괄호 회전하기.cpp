#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

unordered_map<char, char> bracketPair = {{')', '('}, {'}', '{'}, {']', '['}};

bool isValid(string &s, int start)
{
    stack<char> stk;
    unsigned int sz = s.size();
    
    for(int i = 0; i < sz; i++)
    {
        char ch = s[(start + i) % sz];
        
        // ch가 닫힌 괄호인 경우
        if(bracketPair.count(ch))
        {
            if(stk.empty() || stk.top() != bracketPair[ch])
                return false;
            
            // ch와 짝이 맞는 열린 괄호면 해당 열린 괄호 제거
            stk.pop();
        }
        else
        {
            stk.push(ch);
        }
    }
    
    return stk.empty(); 
}

int solution(string s)
{
    int answer = 0;
    int n = s.size();
    
    for(int i = 0; i < s.size(); i++)
        answer += isValid(s, i);
    
    return answer;
}