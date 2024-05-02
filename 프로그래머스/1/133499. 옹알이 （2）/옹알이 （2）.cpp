#include <string>
#include <vector>

using namespace std;

int solution(vector<string> babbling) {
    int answer = 0;
    bool flag = true;
    int check;
    
    for(string s : babbling)
    {
        check = 0;
        flag = true;
        
        for(int i = 0; i < s.size(); i++)
        {
            if(s.substr(i, 3) == "aya" && check != 1)
            {
                i += 2;
                check = 1;
            }
            else if(s.substr(i, 2) == "ye" && check != 2)
            {
                i += 1;
                check = 2;
            }
            else if(s.substr(i, 3) == "woo" && check != 3)
            {
                i += 2;
                check = 3;
            }
            else if(s.substr(i, 2) == "ma" && check != 4)
            {
                i += 1;
                check = 4;
            }
            else
            {
                flag = false;
                break;
            }
        }
        
        if(flag)
            answer++;
    }
    
    return answer;
}