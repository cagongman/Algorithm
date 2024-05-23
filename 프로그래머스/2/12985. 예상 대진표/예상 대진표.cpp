#include <iostream>

using namespace std;

int solution(int n, int a, int b)
{
    int answer = 0;
    int A = a;
    int B = b;
    int i = 0;
    
    while(A != B)
    {
        i ++;
        
        A = (A + 1) >> 1;
        B = (B + 1) >> 1;
    }

    return i;
}