#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    vector<int> answer;
    map<string, int> nameYearning;
    
    for(int i = 0; i < name.size(); i++)
        nameYearning[name[i]] = yearning[i];
    
    for(auto& pho : photo)
    {
        int score = 0;
        
        for(auto& p : pho)
        {
            score += nameYearning[p];
        }
        
        answer.push_back(score);
    }
    
    return answer;
}