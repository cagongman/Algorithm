def solution(bandage, health, attacks):
    answer = 0
    lastAttackSec = attacks[-1][0]
    leftHP = health
    bandageTime = 0
    attack_i = 0
    lastAttack = False
    
    for i in range(1, lastAttackSec + 1):
        # 붕대 시간 up
        bandageTime += 1
        sec = attacks[attack_i][0]
        damage = attacks[attack_i][1]
        
        # 붕대 타임 초기화 / 맞았을때 HP 감소 / 죽으면 종료
        if sec == i:
            leftHP -= damage
            attack_i += 1
            bandageTime = 0
            
            if leftHP <= 0:
                return -1
            
        # 체력 회복
        else:
            # 체력 회복시 최대 체력보다 많이 회복되면 최대체력으로 초기화
            if leftHP + bandage[1] > health:
                leftHP = health
            else:
                leftHP += bandage[1]
                
            if bandageTime % bandage[0] == 0:
                if leftHP + bandage[2] > health:
                    leftHP = health
                else:
                    leftHP += bandage[2]
                    
        print(i, "leftHP", leftHP, "bandageTime", bandageTime, "attack",sec, damage)
    
    return leftHP