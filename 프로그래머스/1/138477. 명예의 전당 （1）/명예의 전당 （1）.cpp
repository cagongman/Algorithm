#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int k, vector<int> score) 
{
    vector<int> answer;
    vector<int> s;
    
    for(int i = 0; i < score.size(); i ++)
    {
        s.push_back(score[i]);
        sort(s.begin(), s.end(), greater<>());
        
        if ( s.size() > k)
            s.erase(s.begin() + k, s.end());

        answer.push_back(s[s.size() - 1]);
    }
    
    return answer;
}