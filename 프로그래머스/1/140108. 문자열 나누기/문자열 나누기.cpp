#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    int countX = 0;
    int countOther = 0;
    char x = s[0];
    
    for(int i = 0; i < s.size(); i++) {
        if(x == s[i]) {
            countX++;
        } else {
            countOther++;  
        }
        
        if(countX == countOther) {
            x = s[i + 1];
            countX = 0;
            countOther = 0;
            answer++;
        }else{
            if(i == s.size() - 1)
                answer++;
        }
    }
    
    return answer;
}