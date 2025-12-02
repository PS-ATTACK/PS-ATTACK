n, x = map(int, input().split())
b = list(map(int, input().split()))

for i in range(0 , n):
    if b[i] < x:
        print(b[i], end =" ")
   