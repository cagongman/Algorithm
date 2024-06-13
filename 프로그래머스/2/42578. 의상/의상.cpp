#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    unordered_map<string, int> _clothes;
    
    for(auto c : clothes)
        _clothes[c[1]]++;
    
    for(auto c : _clothes)
        answer *= (c.second+=1);
    
    return answer - 1;
}