def BubbleSort(l:list):
    n = len(l)
    for i in range(n):
        for j in range(n - i - 1):
            if l[j] > l[j + 1]:
                temp = l[j]
                l[j] = l[j + 1]
                l[j + 1] = temp
    return l


if __name__ == '__main__':
    l = [3,5,1,2,547,6,12,65,2,7,1347,23]
    print(BubbleSort(l)) 