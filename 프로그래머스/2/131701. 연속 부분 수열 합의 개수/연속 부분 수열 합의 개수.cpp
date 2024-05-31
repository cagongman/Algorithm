#include <string>
#include <vector>
#include <map>
 #include <numeric>


using namespace std;

int solution(vector<int> elements) {
    int answer = 0;
    map<int, bool> check;
    
    for(int i = 1; i <= elements.size(); i++)
    {
        for(int j = 0; j < elements.size(); j++)
        {
            int sum = 0;
            
            for(int k = 0; k < i; k++)
                sum += elements[(j + k) % elements.size()];
            
            if(check.count(sum) <= 0)
            {
                check[sum] = true;
                answer++;
            }
        }
    }
    
    return answer;
}