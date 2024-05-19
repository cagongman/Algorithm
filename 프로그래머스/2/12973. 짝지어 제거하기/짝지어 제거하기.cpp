#include <iostream>
#include <vector>
#include<string>

using namespace std;

int solution(string s)
{
    vector<char> ary;
    
    ary.push_back(s[0]);
    
    for(int i = 1; i < s.size(); i++)
    {
        if(!ary.empty())
        {
            if(ary.back() == s[i])
            {
                ary.pop_back();
            }
            else 
            {
                ary.push_back(s[i]);
            }
        }
        else
        {
            ary.push_back(s[i]);
        }
    }

    return ary.empty() ? 1 : 0;
}