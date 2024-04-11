#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    unordered_map<string, int> playerIndexMap; // 선수 이름과 인덱스를 매핑
    for (int i = 0; i < players.size(); ++i) {
        playerIndexMap[players[i]] = i;
    }

    for (const string& calledName : callings) {
        int index = playerIndexMap[calledName];
        if (index > 0) { // 첫 번째 위치에 있는 선수는 추월할 수 없으므로 제외
            // 현재 선수와 바로 앞 선수의 위치를 교환
            swap(players[index], players[index - 1]);
            // 맵 업데이트
            playerIndexMap[players[index]] = index;
            playerIndexMap[players[index - 1]] = index - 1;
        }
    }

    return players;
}