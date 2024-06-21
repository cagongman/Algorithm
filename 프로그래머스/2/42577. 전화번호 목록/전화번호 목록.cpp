#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

bool solution(vector<string> phone_book) {
    unordered_map<string, bool> hash;
    
    for(string s : phone_book)
        hash[s] = true;
    
    for(int i = 0; i < phone_book.size(); i++)
    {
        string check = "";
        for(int j = 0; j < phone_book[i].size() - 1; j++)
        {
            check += phone_book[i][j];
            
            if(hash[check])
                return false;
        }
    }
    
    return true;
}