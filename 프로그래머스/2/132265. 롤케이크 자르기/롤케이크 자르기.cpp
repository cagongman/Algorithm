#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

int solution(vector<int> topping) {
    int answer = 0;
    map<int,int> left_m;
    map<int,int> right_m;
    
    for(int i=0; i<topping.size(); i++)
        right_m[topping[i]] += 1;
    
    for(int i=0; i<topping.size(); i++) 
    {
        if(right_m.find(topping[i]) != right_m.end()) 
        {
            right_m[topping[i]]--;
            
            if(right_m[topping[i]]==0)
                right_m.erase(topping[i]);
            
            left_m[topping[i]] += 1;
        }
        
        
        if(left_m.size()==right_m.size())
            answer++;
    }
    
    return answer;
}