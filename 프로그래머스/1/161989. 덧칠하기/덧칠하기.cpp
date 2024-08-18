#include <string>
#include <vector>

using namespace std;

int solution(int n, int m, vector<int> section) {
    int answer = 1;

    int pivot = section[0];
    for(const auto v : section)
    {
        if(v < pivot + m)
        {
            continue;
        }
        else
        {
            pivot = v;
            answer++;
        }
    }

    return answer;
}