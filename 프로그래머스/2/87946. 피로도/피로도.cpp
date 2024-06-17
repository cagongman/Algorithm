#include <string>
#include <vector>

using namespace std;

int answer = 0;
bool check[8];

void dp (int cnt, int k, vector<vector<int>> dungeons)
{
    if(answer < cnt) answer = cnt;
    
    for(int i =0;i<dungeons.size(); i++)
    {
        if(check[i] == false && dungeons[i][0] <= k)
        {
            check[i] = true;
            dp(cnt + 1, k - dungeons[i][1], dungeons);
            check[i] = false;
        }
    }
}

int solution(int k, vector<vector<int>> dungeons) {\
    dp(0, k, dungeons);
    return answer;
}