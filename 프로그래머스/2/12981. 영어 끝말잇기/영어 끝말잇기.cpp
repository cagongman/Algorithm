#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    unordered_map<string, int> history;
    int pNum = 0;
    int turnNum = 0;
    char lastC;
    bool check = true;
    
    history[words[0]] = 1;
    lastC = words[0].back();
    
    cout << lastC << endl;
    
    for(int i = 1; i < words.size(); i++)
    {
        pNum = i % n + 1;
        turnNum = i / n + 1;
        
        if(lastC != words[i].front())
        {
            check = false;
            answer.push_back(pNum);
            answer.push_back(turnNum);
            break;
        }
        
        if(history[words[i]] != 1)
            history[words[i]] = 1;
        else
        {
            check = false;
            answer.push_back(pNum);
            answer.push_back(turnNum);
            break;
        }
        
        lastC = words[i].back();
    }
    
    if(check)
    {
        answer.push_back(0);
        answer.push_back(0);
        return answer;
    }
    else
        return answer;
}