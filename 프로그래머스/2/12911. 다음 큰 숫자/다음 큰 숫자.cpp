#include <string>
#include <vector>
#include <iostream>

using namespace std;

int countOne(int n)
{
    int left;
    int sum = 0;
    
    while(true)
    {
        left = n % 2;
        n = n / 2;
        
        if(left == 1)
            sum++;
        
        if(n == 1)
        {
            sum++;
            break;
        }
    }
    
    return sum;
}

int solution(int n) {
    int answer = 0;
    int count_cur_one;
    int count_next_one;
    
    count_cur_one = countOne(n);
    
    for(int i = 1;;i++)
    {
        count_next_one = countOne(n + i);
        
        if(count_next_one == count_cur_one)
        {
            answer = n + i;
            break;
        }
    }
    
    return answer;
}