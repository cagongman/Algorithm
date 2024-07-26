#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(const string& a, const string& b)
{
    return a + b > b + a;
}

string solution(vector<int> numbers) 
{
    string answer = "";
    vector<string> numbers_str;
    
    for(auto num : numbers)
        numbers_str.push_back(to_string(num));
    
    sort(numbers_str.begin(), numbers_str.end(), compare);
    
    if(numbers_str[0] == "0")
        return "0";
    
    for(string num : numbers_str)
        answer += num;
    
    return answer;
}