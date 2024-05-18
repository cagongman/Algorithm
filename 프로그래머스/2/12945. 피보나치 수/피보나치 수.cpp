#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n) {
    int answer = 0;
    vector<int> ary;
    int m = 1234567;
    
    ary.push_back(0);
    ary.push_back(1);
    ary.push_back(1);
    
    for(int i = 3; i <= n; i++)
    {
        int v = (ary[i - 1] % m + ary[i - 2] % m) % m;
        ary.push_back(v);
    }
    
    return ary.back() % 1234567;
}