def solution(friends, gifts):
    present = {}
    result = {}
    
    for friend in friends:
        present[friend] = {}
        present[friend]["rate"] = 0
        
        for f in friends:
            present[friend][f] = 0
            
        result[friend] = 0
    
    for gift in gifts:
        a, b = gift.split()
        
        present[a][b] += 1
        present[a]["rate"] += 1
        present[b][a] -= 1
        present[b]["rate"] -= 1
        
    for a in friends:
        for b in friends:
            if a == b: continue

            if present[a][b] > 0:
                result[a] += 1
            elif present[a][b] == 0:
                if present[a]["rate"] > present[b]["rate"]:
                    result[a] += 1
                    
    return max(result.values())