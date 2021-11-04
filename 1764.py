my_dict = {}
ret = []
N, M = map(int, input().split())
for i in range(N + M):
    key = input()
    if key in my_dict:
        ret.append(key)
    else:
        my_dict[key] = 1
print(len(ret))
ret.sort()
for list in ret:
    print(list)
    