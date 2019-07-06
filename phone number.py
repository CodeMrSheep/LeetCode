from functools import reduce
digits = '23'
res = []
tolist = []
dict1 = {}
for i in range(2,7):
    dict1[str(i)] = ''
    for j in range(3):
        dict1[str(i)] += chr(91+3*i+j)
dict1['7'] = 'pqrs'
dict1['8'] = 'tuv'
dict1['9'] = 'wxyz'
permu = lambda x: reduce(lambda x, y: [str(i)+str(j) for i in x for j in y], x)
for digit in digits:
    print(dict1[digit])
    tolist.append(dict1[digit])
print(tolist)
res = permu(tolist)
print(res)