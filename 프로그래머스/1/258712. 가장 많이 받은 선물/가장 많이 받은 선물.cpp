#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int solution(vector<string> friends, vector<string> gifts) {
    map<string, map<string, int>> present;
    map<string, int> result;

    // 각 친구에 대한 초기 설정
    for (auto& friendName : friends) {
        present[friendName]["rate"] = 0;
        for (auto& f : friends) {
            present[friendName][f] = 0;
        }
        result[friendName] = 0;
    }

    // 선물 기록
    for (auto& gift : gifts) {
        size_t spacePos = gift.find(" ");
        string a = gift.substr(0, spacePos);
        string b = gift.substr(spacePos + 1);

        present[a][b] += 1;
        present[a]["rate"] += 1;
        present[b][a] -= 1;
        present[b]["rate"] -= 1;
    }

    // 결과 계산
    for (auto& a : friends) {
        for (auto& b : friends) {
            if (a == b) continue;

            if (present[a][b] > 0) {
                result[a] += 1;
            } else if (present[a][b] == 0) {
                if (present[a]["rate"] > present[b]["rate"]) {
                    result[a] += 1;
                }
            }
        }
    }

    // 최대값 찾기
    int maxValue = 0;
    for (auto& r : result) {
        maxValue = max(maxValue, r.second);
    }

    return maxValue;
}