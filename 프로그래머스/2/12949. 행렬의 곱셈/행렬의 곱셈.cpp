#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;
    
    for(int y = 0; y < arr1.size(); y++)
    {
        vector<int> temp;
        
        for(int x = 0; x < arr2[0].size(); x++)
        {
            int sum = 0;
            
            for(int i = 0; i < arr2.size(); i++)
            {
                sum += arr1[y][i] * arr2[i][x];
            }
            
            temp.push_back(sum);
        }
        
        answer.push_back(temp);
    }
    
    return answer;
}