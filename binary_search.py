def BinarySearch(l:list, target:int) -> int :
    low = 0
    high = len(l)
    mid = int((low + high) / 2)
    while low <= high:
        if l[mid] == target:
            return 1
        elif l[mid] < target:
            low = mid + 1
            mid = int((low + high) / 2)
        elif l[mid] > target:
            high = mid - 1
            mid = int((low + high) / 2)
    return -1

if __name__ == '__main__':
    l = [1,2,3,4,5,6]
    print(BinarySearch(l, 5))