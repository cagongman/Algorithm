#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <map>

using namespace std;


int calculate_date2int(int year, int month, int day, int remain) {
    int result = 0;
    
    result += (year - 2000) * 12 * 28;
    result += month * 28;
    result += day;
    
    return result + remain * 28;
}

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    istringstream iss(today);
    int year, month, day;
    int todayInt;
    
    char del;
    
    char rule;
    int ruleTerm;
    
    map<char, int> termMap;
    
    iss >> year >> del >> month >> del >> day;
    todayInt = calculate_date2int(year, month, day, 0);
    
    for(auto& term : terms) {
        iss.clear();
        iss.str(term);
        iss >> rule >> ruleTerm;
        termMap[rule] = ruleTerm;
    }
    
    for(int i = 0; i < privacies.size(); i++) {
        string date_p;
        int year_p, month_p, day_p;
        char del1, del2, rule_p; 
        
        iss.clear();
        iss.str(privacies[i]);
        iss >> year_p >> del1 >> month_p >> del2 >> day_p >> rule_p;
        
        // cout << todayInt << " " << calculate_date2int(year_p, month_p, day_p, termMap[rule_p]) << endl;
        // cout << termMap[rule_p] << endl;
        
        if(todayInt >= calculate_date2int(year_p, month_p, day_p, termMap[rule_p])) 
            answer.push_back(i + 1);
    }
    
    return answer;
}