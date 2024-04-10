#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<string>> board, int h, int w) {
    int boardLength = board.capacity();
    int count = 0;
    int direction[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    int dh, dw;
    
    for(int i = 0; i < 4; i++)
    {
        dh = h + direction[i][0];
        dw = w + direction[i][1];
        
        if(dh < 0 || dh > boardLength - 1 || dw < 0 || dw > boardLength - 1)
        {
            continue;
        }
        else
        {
            if(board[h][w] == board[dh][dw])
                count++;
        }
    }
    
    return count;
}