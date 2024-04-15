#include <string>
#include <sstream>
#include <vector>

using namespace std;

vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer;
    int x = 0, y = 0;
    int width, height;
    
    width = park[0].size();
    height = park.size();
    
    for(int i = 0; i < height; i++) {
        bool check = false;
        for(int j = 0; j < width; j++) {
            if(park[i][j] == 'S') {
                x = j;
                y = i;
                check = true;
            }
        }
        if(check)
            break;
    }
    
    for(auto& rout : routes) {
        int num;
        bool canGo = true;
        string dir;
        istringstream iss(rout);

        iss >> dir >> num;
        
        switch(rout[0]) {
            case 'N':
                if(y - num < 0) {
                    canGo = false;
                    continue;
                }
                for(int i = 1; i <= num; i++) {
                    if(park[y - i][x] == 'X') {
                        canGo = false;
                        break;
                    }
                }
                
                if(canGo)
                    y -= num;    
                break;
                
            case 'S':
                if(y + num >= height){
                    canGo = false;
                    continue;
                }
                for(int i = 1; i <= num; i++) {
                    if(park[y + i][x] == 'X') {
                        canGo = false;
                        break;
                    }
                }
                
                if(canGo)
                    y += num;   
                break;
                
            case 'W':
                if(x - num < 0){
                    canGo = false;
                    continue;
                }
                for(int i = 1; i <= num; i++) {
                    if(park[y][x - i] == 'X') {
                        canGo = false;
                        break;
                    }
                }
                
                if(canGo)
                    x -= num;   
                break;
                
            case 'E':
                if(x + num >= width){
                    canGo = false;
                    continue;
                }
                for(int i = 1; i <= num; i++) {
                    if(park[y][x + i] == 'X') {
                        canGo = false;
                        break;
                    }
                }
                
                if(canGo)
                    x += num;
                break;
        }
    }
    
    answer.push_back(y);
    answer.push_back(x);
    
    return answer;
}