my_list = []
N = int(input())
for i in range(N):
    x, y = map(int, input().split())
    my_list.append((x, y))
sort_list = sorted(my_list, key = lambda x : (x[0], x[1]))
for tuples in sort_list:
    print(tuples[0], tuples[1])