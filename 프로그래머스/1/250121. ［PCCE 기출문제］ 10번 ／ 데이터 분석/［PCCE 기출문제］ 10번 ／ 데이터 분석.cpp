#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> data, string ext, int val_ext, string sort_by) {
    vector<vector<int>> answer;
    int n = data.size();
    string check[4] = {"code", "date", "maximum", "remain"};
    int ext_i = 0;
    int sort_i = 0;
    
    for(int i = 0; i < 4; i++)
    {
        if(check[i] == ext)
            ext_i = i;
        
        if(check[i] == sort_by)
            sort_i = i; 
    }
    
    for(int i = 0; i < data.size(); i++)
    {
        if(data[i][ext_i] < val_ext)
            answer.push_back(data[i]);
    }
    
    sort(answer.begin(), answer.end(), [sort_i](const vector<int>& a, const vector<int>& b) {
        return a[sort_i] < b[sort_i];
    });
    
    return answer;
}