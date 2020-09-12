'''
https://leetcode-cn.com/problems/average-of-levels-in-binary-tree/
bfs
'''
from typing import List
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
class Solution:
    def __init__(self):
        self.retL = []

    def averageOfLevels(self, root: TreeNode) -> List[float]:
        if root == None:
            return []
        currentList = []
        currentCount = 0
        nextCount = 1
        currentList.append(root)
        currentLevelSum = 0
        while len(currentList) != 0:
            currentLevelSum = 0
            currentCount = nextCount
            nextCount = 0
            for i in range(currentCount):
                tempNode = currentList.pop(0)
                if tempNode.left != None:
                    currentList.append(tempNode.left)
                    nextCount += 1
                if tempNode.right != None:
                    currentList.append(tempNode.right)
                    nextCount += 1 
                currentLevelSum += tempNode.val
            self.retL.append(currentLevelSum/currentCount)
        return self.retL