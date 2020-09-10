'''
dfs 

'''
from typing import List
import copy
class Solution:
    def __init__(self):
        self.returnL = []
        self.tmpL = []

    def checkSame(self, temp):
        if len(self.returnL) == 0:
            return True
        for i in self.returnL:
            if len(i) != len(temp):
                continue
            isSame = True
            for j in range(len(temp)):
                if temp[j] != i[j]:
                    isSame = False
            if isSame == True:
                return False
        return True

    def dfs(self, candidates, currentIndex, target):
        if sum(self.tmpL) == target:
            if self.checkSame(self.tmpL) == True:
                self.returnL.append(copy.deepcopy(self.tmpL))
            return
        elif sum(self.tmpL) > target:
            return
        elif currentIndex >= len(candidates):
            return
        self.tmpL.append(candidates[currentIndex])
        self.dfs(candidates, currentIndex + 1, target)
        self.tmpL.pop()
        self.dfs(candidates, currentIndex + 1, target)

    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        if len(candidates) < 1:
            return candidates
        candidates.sort()
        for i in range(len(candidates)):
            self.dfs(candidates, i, target)
        self.returnL
        return self.returnL

if __name__ == "__main__":
    a = Solution()
    print(a.combinationSum2([4,2,5,2,5,3,1,5,2,2], 9))