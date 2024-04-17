#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    map<char, int> result = {
        {'R', 0}, {'T', 0}, {'C', 0}, {'F', 0},
        {'J', 0}, {'F', 0}, {'A', 0}, {'N', 0}
    };
    
    for(int i = 0; i < choices.size(); i++) {
        if(choices[i] < 4) {
            result[survey[i][0]] += (4 - choices[i]);
        } 
        else if(choices[i] > 4) {
            result[survey[i][1]] += (choices[i] - 4);
        }
    }
    
    answer += result['R'] >= result['T'] ? 'R' : 'T';
    answer += result['C'] >= result['F'] ? 'C' : 'F';
    answer += result['J'] >= result['M'] ? 'J' : 'M';
    answer += result['A'] >= result['N'] ? 'A' : 'N';

    return answer;
}