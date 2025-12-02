import sys

# input = sys.stdin.readline()


def nthEnd(n):
    """
    :param n:
    n을 받아서 n번째 종말 제목을 리턴한다.
    0일때는 666
    1일때는 1666
    :return:
    """

    i = 666
    cnt = 0
    while True:
        if str(i).count("666") >= 1:
            cnt += 1
        if cnt == n:
            break
        i += 1
    return i


n = int(input())
result = nthEnd(n)
print(result)
