#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    vector<int> v(1000000, 0);
    
    for(int i = 2; i <= n; ++i) {
        if(v[i] == 0) {
            answer++;
            for(int j = 1; i * j <= n; ++j) {
                v[i * j] = 1;
            }
        }
    }
    return answer;
}