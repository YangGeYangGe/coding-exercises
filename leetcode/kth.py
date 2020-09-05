'''
https://leetcode-cn.com/problems/permutation-sequence/submissions/

可选数字为[1,2,3,...,n]

n * (n - 1) * ... * 1
可以定位到k的下一个数字属于哪个区间
if x = k / (n-1 * ... * 1) && y = k % (n-1 * ... * 1) != 0
    k的下一个数字就是第x + 1个 (index为x)
if x = k / (n-1 * ... * 1) && y = k % (n-1 * ... * 1) == 0
    k的下一个数字就是第x个 (index为x - 1)

可以用recursive的方式求出结果，不停的选出下一个数字，并在原List中踢出已选过的数字
'''

class Solution:
    def __init__(self):
        self.retStr = ""
    def getPermutation(self, n: int, k: int) -> str:
        def Recursive(l: list, n: int, k:int):
            if n == 1:
                temp = l.pop()
                self.retStr += str(temp)
                return
            divisor = 1
            for i in range(1, n):
                divisor *= i
            x = int(k / divisor)
            y = k % divisor
            if y == 0:
                temp = l.pop(x - 1)
                self.retStr += str(temp)
            else:
                temp = l.pop(x)
                self.retStr += str(temp)
            Recursive(l, n - 1, k = y)
        digits = [1] * n
        for i in range(n):
            digits[i] = i + 1
        Recursive(digits, n, k)
        return self.retStr

if __name__ == '__main__':
    a = Solution()
    #2314
    print(a.getPermutation(3,3))