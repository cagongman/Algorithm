import Foundation

let input = readLine()!.split(separator: " ").map { Int($0)! }
let N = input[0]
let M = input[1]

var unheard = Set<String>() // 듣도 못한 사람을 저장할 집합
var unseen = Set<String>() // 보도 못한 사람을 저장할 집합

for _ in 0..<N {
    unheard.insert(readLine()!) // 듣도 못한 사람 추가
}

for _ in 0..<M {
    unseen.insert(readLine()!) // 보도 못한 사람 추가
}

// 듣도 못한 사람과 보도 못한 사람의 교집합을 구하고 사전순으로 정렬
let result = unheard.intersection(unseen).sorted()

// 결과 출력
print(result.count) // 듣보잡의 수
for name in result {
    print(name) // 듣보잡의 명단
}
