overlap = []
ret = []
N = int(input())
for i in range(N):
    key = input()
    if not key in overlap:
        overlap.append(key)
        ret.append([key, len(key)])
sort_ret = sorted(ret, key = lambda x : (x[1], x[0]))
for key in sort_ret:
    print(key[0])
