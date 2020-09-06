'''
quick sort
https://blog.csdn.net/newmemory/article/details/88598032
https://www.jianshu.com/p/2b2f1f79984e
'''

def quick_sort(nums: list, left: int, right: int) -> None:
    if left < right:
        i = left
        j = right
        pivot = nums[left]
        while i != j:
            while j > i and nums[j] > pivot:
                j -= 1
            if j > i:
                nums[i] = nums[j]
                i += 1

            while i < j and nums[i] < pivot:
                i += 1
            if i < j:
                nums[j] = nums[i]
                j -= 1
        nums[i] = pivot
        quick_sort(nums, left, i-1)
        quick_sort(nums, i+1, right)

# 测试代码
import random

data = [random.randint(-100, 100) for _ in range(10)]
quick_sort(data, 0, len(data) - 1)
print(data)
