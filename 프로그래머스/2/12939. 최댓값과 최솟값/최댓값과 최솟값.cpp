#include <string>
#include <vector>
#include <sstream>
#include <iostream>

using namespace std;

string solution(string s) {
    int max = -10000;
    int min = 10000;
    int data;
    string answer = "";
    string sub_data = "";
    
    for(char c : s) 
    {
        if(c == ' ') 
        {
            data = stoi(sub_data);
            sub_data = "";
            
            max = data > max ? data : max;
            min = data < min ? data : min;
        }
        else 
        {
            sub_data += c;    
        }
    }
    
    data = stoi(sub_data);
    max = data > max ? data : max;
    min = data < min ? data : min;
    
    answer = to_string(min) + " " + to_string(max);
    
    return answer;
}