#include <string>
#include <vector>
#include <utility>
#include <algorithm>
#include <iostream>

using namespace std;

bool compare(const pair<int,float>& a, const pair<int, float>& b)
{
    if (a.second == b.second)
        return a.first < b.first;
    return a.second > b.second;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<int> stageNum(N + 2, 0);
    vector<pair<int, float>> failPercent;
    
    // 각 스테이지에 머물러있는 사람 수 저장
    for(int i = 0; i < stages.size(); i++)
        stageNum[stages[i]] += 1;
    

    int pastStageNum = 0;
    int playerNum = stages.size();
    
    for(int i = 1; i <= N; i++)
    {
        // 아직 해당 스테이지에 있는 사람 / (전체 플레이어 - 전 스테이지까지의 인원)
        failPercent.push_back(make_pair(i, (float)stageNum[i] / (float)(playerNum - pastStageNum)));

        cout << pastStageNum << endl;
        
        // 전 스테이지까지의 인원 업데이트
        pastStageNum += stageNum[i];
        
        if(pastStageNum == playerNum)
        {
            for(int j = i + 1; j <= N; j++)
                failPercent.push_back(make_pair(j, 0.f));
            
            break;
        }
    }
    
    sort(failPercent.begin(), failPercent.end(), compare);
    
    for(int i = 0; i < failPercent.size(); i++)
        answer.push_back(failPercent[i].first);
    
    return answer;
}