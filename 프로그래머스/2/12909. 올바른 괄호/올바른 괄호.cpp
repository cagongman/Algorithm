#include<string>
#include <iostream>
#include <vector>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    vector<char> stack;
    
    for(char c : s) {
        if(stack.size() == 0)
            stack.push_back(c);
        else {
            if(stack.back() == '(' && c == ')')
                stack.pop_back();
            else
                stack.push_back(c);
        }
    }

    if(stack.size() == 0)
        return true;
    else
        return false;
}