
# 输入一个链表，输出该链表中倒数第k个结点。
# -*- coding:utf-8 -*-
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def FindKthToTail(self, head, k):
        # write code here
        if head == None or k == 0:
            return None
        
        lap = k - 1
        left = head
        right = head

        for i in range(0,lap):
            right = right.next
        if right == None:
            return None
        
        while right.next != None:
            left = left.next
            right = right.next
        return left

        # l = []
        # while head != None:
        #     l.append(head)
        #     head = head.next
        # if len(l) < k or k < 1:
        #     return None
        # return l[-k]