def lcs(a, b):
    lens = len(a)
    res = [[0 for i in range(lens+1)] for j in range(lens+1)]
    for i in range(lens):
        for j in range(lens):
            if a[i] == b[j]:
                res[i+1][j+1] = res[i][j]+1
    return res

a = raw_input()
b = a[::-1]
max = 0
res = lcs(a, b)
for i in res:
    for j in i:
        if j > max:
            max = j
print max
