# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

'''
bfs

https://leetcode-cn.com/problems/list-of-depth-lcci/submissions/
'''
from typing import List
import copy
class Solution:
    def __init__(self):
        self.ret = []
    def listOfDepth(self, tree: TreeNode) -> List[ListNode]:
        if tree == None:
            return []
        currentList = []
        currentCount = 0
        nextCount = 1
        currentList.append(copy.deepcopy(tree))
        while len(currentList) != 0:
            tempHead = ListNode(0)
            currentNode = tempHead
            currentCount = nextCount
            nextCount = 0

            for i in range(currentCount):
                temp = currentList.pop(0)
                if temp.left != None:
                    currentList.append(copy.deepcopy(temp.left))
                    nextCount += 1
                if temp.right != None:
                    currentList.append(copy.deepcopy(temp.right))
                    nextCount += 1

                currentNode.next = ListNode(temp.val)
                currentNode = currentNode.next

            self.ret.append(tempHead.next)
        #print(self.ret)
        return self.ret