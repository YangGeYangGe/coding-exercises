
# https://leetcode.com/problems/jump-game/description/
# Given an array of non-negative integers, you are initially positioned at the first index of the array.

# Each element in the array represents your maximum jump length at that position.

# Determine if you are able to reach the last index.
# Input: [2,3,1,1,4]
# Output: true
# Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
# class Solution:
class Solution:
    def canJump(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        l = [False]*len(nums)
        l[-1] = True
        for i in range(len(nums)-2, -1, -1):
            
            if nums[i] == 0:
                l[i] = False
                continue
            for j in range(i+1, i+nums[i]+1):
                
                if l[j] == True:
                    l[i] = True
                    break
                    
                    
        return l[0]
                    
                    