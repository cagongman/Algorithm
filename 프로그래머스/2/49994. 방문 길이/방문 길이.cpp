#include <string>
#include <unordered_map>
#include <utility>

using namespace std;

char reverse(char c)
{
    switch(c)
    {
        case 'U':
            return 'D';
        case 'D':
            return 'U';
        case 'L':
            return 'R';
        case 'R':
            return 'L';
    }
}

int solution(string dirs) {
    int answer = 0;
    bool check = false;
    unordered_map<string, string> history;
    pair<int, int> curLoc(0, 0);
    
    for(int i = 0; i < dirs.length(); i++) 
    {
        check = true;
        string key1 = to_string(curLoc.first) + to_string(curLoc.second);
        
        switch(dirs[i])
        {
            case 'U':
                if(curLoc.second + 1 <= 5)
                    curLoc.second += 1;
                else
                    check = false;
                break;
            case 'D':
                if(curLoc.second - 1 >= -5)
                    curLoc.second -= 1;
                else
                    check = false;
                break;
            case 'L':
                if(curLoc.first - 1 >= -5)
                    curLoc.first -= 1;
                else
                    check = false;
                break;
            case 'R':
                if(curLoc.first + 1 <= 5)
                    curLoc.first += 1;
                else
                    check = false;
                break;
        }
        
        string key2 = to_string(curLoc.first) + to_string(curLoc.second);
        
        if(history[key1].find(dirs[i]) == string::npos && history[key2].find(reverse(dirs[i])) && check)
        {
            history[key1] += dirs[i];
            history[key2] += reverse(dirs[i]);
            answer++;
        }
    }
    
    return answer;
}