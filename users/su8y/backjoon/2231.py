import sys
def decomposition(n: int):
    for i in range(n):
        sum = i
        # 각 자리수 더하기
        for digit in str(i):
            sum += int(digit)
        if sum == n :
            return i
    return 0


n = int(input())
result = decomposition(n)
print(result)
