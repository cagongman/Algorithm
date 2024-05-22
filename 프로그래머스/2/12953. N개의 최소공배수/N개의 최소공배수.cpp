#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> arr) {
    int answer = 0;
    int max = *max_element(arr.begin(), arr.end());
    bool flag;
    
    while(true)
    {
        flag = true;
        
        for(int i = 0; i < arr.size(); i++)
        {
            if(max % arr[i] != 0)
            {
                flag = false;
                break;
            }
        }
        
        if(flag)
            break;
        
        max++;
    }
    
    return max;
}