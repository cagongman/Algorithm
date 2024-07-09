#include <string>
#include <vector>

using namespace std;

char dic[5] = {'A', 'E', 'I', 'O', 'U'};
int cnt = -1;
int answer = 0;
string target = "";

void MakeWord(string word)
{
    cnt++;
    
    if(word == target)
    {
        answer = cnt;
        return;
    }
    
    if(word.length() >= 5)
        return;
    
    for(int i = 0; i < 5; i++)
        MakeWord(word + dic[i]);
}

int solution(string word) {
    target = word;
    
    MakeWord("");
    
    return answer;
}