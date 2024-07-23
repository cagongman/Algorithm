#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> sum = {0,0,0};
    
    int p1[] = { 1, 2, 3, 4, 5 };
    int p2[] = {2,1,2,3,2,4,2,5};
    int p3[] = {3,3,1,1,2,2,4,4,5,5};
    
    for(int i = 0; i < answers.size(); i++)
    {
        if(answers[i] == p1[i % (sizeof(p1)/sizeof(p1[0]))])
            sum[0]++;
        if(answers[i] == p2[i % (sizeof(p2)/sizeof(p2[0]))])
            sum[1]++;
        if(answers[i] == p3[i % (sizeof(p3)/sizeof(p3[0]))])
            sum[2]++;
    }
    
    for(int i = 0; i < 3; i++)
    {
        if(*max_element(sum.begin(), sum.end()) == sum[i])
            answer.push_back(i + 1);
    }
    
    return answer;
}