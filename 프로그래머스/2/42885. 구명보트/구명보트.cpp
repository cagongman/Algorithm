#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    int left = limit;
    int front = 0, back = people.size() - 1;
    
    sort(people.begin(), people.end());
    
    while(front <= back)
    {
        // cout << "kg: " << people[back];
            
        left = limit - people[back--];
        
        if(people[front] <= left)
        {
            // cout << ", " << people[front];
            front++;
        }
        
        answer++;
        
        // cout << endl;
    }
    
    return answer;
}