#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int currentState = 0;
    int num = progresses.size();
    
    while(currentState < num)
    {
        int exploreCnt = 0;
        
        for(int i = currentState; i < num; i++)
        {
            progresses[i] += speeds[i];
            
            if(progresses[currentState] >= 100 && progresses[i] >= 100)
            {
                exploreCnt++;
                currentState++;
            }
        }
        
        if(exploreCnt != 0)
            answer.push_back(exploreCnt);
    }
    
    return answer;
}