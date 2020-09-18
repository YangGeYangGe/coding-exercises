'''
https://leetcode-cn.com/problems/binary-tree-right-side-view/submissions/
BFS
取每一层的最后一个
'''

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def rightSideView(self, root: TreeNode) -> List[int]:
        if root == None:
            return []
        ret = []
        tempQueue = []

        currentCount = 0
        nextCount = 1
        tempQueue.append(root)
        while len(tempQueue) != 0:
            currentCount = nextCount
            nextCount = 0
            for i in range(currentCount):
                tempNode = tempQueue.pop(0)
                if tempNode.left != None:
                    nextCount += 1
                    tempQueue.append(tempNode.left)
                if tempNode.right != None:
                    nextCount += 1
                    tempQueue.append(tempNode.right)
                if i == currentCount - 1:
                    ret.append(tempNode.val)
        #print(ret)
        return ret
