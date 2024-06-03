#include <string>
#include <vector>
#include <list>
#include <stack>

using namespace std;


bool CheckPop(char front, char back)
{
   if (front == '(' && back == ')') return true;
    if (front == '[' && back == ']') return true;
    if (front == '{' && back == '}') return true;
    return false;
}

int solution(string s) {
    int answer = 0;
    list<char> Brackets;
    
    for(char c : s)
        Brackets.push_back(c);
    
    for(int i = 0; i < s.size(); i++)
    {
        if(i != 0)
        {
            int temp;
            temp = Brackets.front();
            Brackets.pop_front();
            Brackets.push_back(temp);
        }
        
        stack<char> check;
        
        for(auto value : Brackets)
        {
            if(check.empty())
                check.push(value);
            else
            {
                if(CheckPop(check.top(), value))
                    check.pop();
                else
                    check.push(value);
            }
        }
        
        if(check.empty())
            answer++;
    }
        
    return answer;
}