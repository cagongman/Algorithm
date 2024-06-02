#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    int count = 0;
    map<int, int> TangerineMap;
    vector<int> countAry;
    
    for(int type : tangerine)
    {
        if(TangerineMap[type] > 0)
            TangerineMap[type] += 1;
        else
            TangerineMap[type] = 1;
    }
    
    for(auto t : TangerineMap)
        countAry.push_back(t.second);
    
    sort(countAry.begin(), countAry.end(), greater<int>());
    
    for(int i = 0; i < countAry.size(); i++)
    {
        count += countAry[i];
        
        if(count >= k)
            return i + 1;
    }
}