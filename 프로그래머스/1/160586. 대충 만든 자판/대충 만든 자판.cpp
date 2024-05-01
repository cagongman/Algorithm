#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer;
    map<char, int> charCount;
    
    for(int i = 0; i < keymap.size(); i++)
    {
        for(int j = 0; j < keymap[i].size(); j++)
        {
            if(charCount[keymap[i][j]] != 0)
            {
                if(j + 1 < charCount[keymap[i][j]]) 
                {
                    charCount[keymap[i][j]] = j + 1;
                }
            }
            else
            {
                charCount[keymap[i][j]] = j + 1;
            }
        }
    }
    
    int sum = 0;
    for(int i = 0; i < targets.size(); i++)
    {
        sum = 0;
        for(int j = 0; j < targets[i].size(); j++) {
            if(charCount[targets[i][j]] == 0) {
                sum = 0;
                break;
            }
            
            sum += charCount[targets[i][j]];            
        }
        
        sum = sum == 0 ? -1 : sum;
        answer.push_back(sum);
    }
    
    return answer;
}