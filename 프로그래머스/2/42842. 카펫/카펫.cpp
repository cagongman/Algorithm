#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int x, y;
    
    for(int i = 1; i <= yellow; i++)
    {
        if(yellow % i != 0)
            continue;
        
        
        x = yellow / i;
        y = i;
        
        cout << x << ", " << y << endl;
        
        if(((y + 2) * 2) + (x * 2) == brown)
        {
            answer.push_back(x + 2);
            answer.push_back(y + 2);
            break;
        }
    }
    
    return answer;
}