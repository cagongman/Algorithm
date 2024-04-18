#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> wallpaper) {
    vector<int> answer;
    int minX = 55, maxX = 0;
    int minY = 55, maxY = 0;
    
    for(int y = 0; y < wallpaper.size(); y++) {
        for(int x = 0; x < wallpaper[0].size(); x++) {
            if(wallpaper[y][x] == '#') {
                cout << y << " " << x << endl; 
                minX = minX > x ? x : minX;
                cout << "minX" << minX << endl;
                minY = minY > y ? y : minY;
                maxX = maxX < x ? x : maxX;
                maxY = maxY < y ? y : maxY;
            }
        }
    }
    
    answer = {minY, minX, maxY + 1, maxX + 1};
    
    return answer;
}