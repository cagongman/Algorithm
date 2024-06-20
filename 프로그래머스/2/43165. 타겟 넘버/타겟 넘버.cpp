#include <string>
#include <vector>

using namespace std;

int answer = 0;
int _target = 0;

void dfs(int depth, int curSum, vector<int> numbers, bool add)
{
    int sum = 0;
    
    if(add)
        sum = curSum + numbers[depth];
    else
        sum = curSum - numbers[depth];
    
    if(depth == numbers.size() - 1)
    {
        if(sum == _target)
            answer++;
        
        return;
    }
    
    dfs(depth + 1, sum, numbers, true);
    dfs(depth + 1, sum, numbers, false);
}

int solution(vector<int> numbers, int target) {
    _target = target;
    dfs(0, 0, numbers, true);
    dfs(0, 0, numbers, false);
    
    return answer;
}