my_list = []
N = int(input())
for i in range(N):
    age, name = input().split()
    my_list.append([name, int(age), i])
sort_list = sorted(my_list, key = lambda x : (x[1], x[2]))
for lists in sort_list:
    print(lists[1], lists[0])
