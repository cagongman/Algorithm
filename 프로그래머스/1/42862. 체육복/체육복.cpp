#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    int reserve_i = 0;
    vector<int> student(n + 1, 0);
    
    for(int r : reserve) 
        student[r] += 1;
    
    for(int l : lost)
        student[l] -= 1;
    
    for(int i = 1; i < n + 1; i++){
        if(student[i] == 0 || student[i] == 1)
            answer++;
        else if(student[i] == -1) 
        {
            if(student[i - 1] == 1)
            {
                answer++;
            }
            else if(student[i + 1] == 1)
            {
                answer++;
                student[i + 1] -= 1;
            }
        }
    }
    
    return answer;
}