
# https://leetcode.com/problems/bitwise-ors-of-subarrays/description/
class Solution:
    def subarrayBitwiseORs(self, A):
        """
        :type A: List[int]
        :rtype: int
        """
        s = []
        if len(A) == 0:
            return 0
        if len(A) == 1:
            return 1
        if len(A) == 2:
            return len(list(set([A[0], A[1], A[0]|A[1]])))
        s.append([A[-1]])
        s.append([A[-2]|A[-1],A[-2]])
        testint = []
        for idx in range(len(A)-3, -1, -1):
            testint = []
            for element in s[-1]:
                testint.append(A[idx] | element)
            testint.append(A[idx])
            s.append(testint)
        result = []
        for t in s:
            result += t
        result = list(set(result))
 
        return len(result)
        