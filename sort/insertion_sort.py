'''
https://blog.csdn.net/z_feng12489/article/details/94634546
insert sort
'''
def insertSort(data):
    for i in range(1, len(data)):
        value = data[i]
        j = i - 1
        while j >= 0:
            if data[j] > value:
                data[j + 1] = data[j]
            else:
                break
            j -= 1
        # data[j] <= value
        data[j + 1] = value
    return data

import random

data = [random.randint(-100, 100) for _ in range(10)]
insertSort(data)
print(data)
