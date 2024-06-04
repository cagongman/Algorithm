#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

// 할인하는 제품은 하루에 하나

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    unordered_map<string, int> wantDic;
    unordered_map<string, int> checkDic;
    int answer = 0;
    bool flag = true;
    
    for(int i = 0; i < number.size(); i++)
        wantDic[want[i]] = number[i];
    
    for(int i = 0; i < discount.size() - 9; i++)
    {
        flag = true;
        checkDic = wantDic;
        
        for(int j = 0; j < 10; j++)
        {
            if(checkDic[discount[i + j]] != 0)
                checkDic[discount[i + j]] -= 1;
            else
            {
                flag = false;
                break;
            }
        }
        
        if(flag) answer++;
    }
    
    return answer;
}