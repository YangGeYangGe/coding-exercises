# https://leetcode.com/problems/partition-equal-subset-sum/description/
# Given a non-empty array containing only positive integers, find 
# if the array can be partitioned into two subsets such that 
# the sum of elements in both subsets is equal.

# Example 1:

# Input: [1, 5, 11, 5]

# Output: true

# Explanation: The array can be partitioned as [1, 5, 5] and [11].
# https://leetcode.com/problems/partition-equal-subset-sum/discuss/90592/01-knapsack-detailed-explanation
class Solution:
    def canPartition(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        sum = 0
        for i in nums:
            sum += i
        if sum % 2 == 1:
            return False 
        sum /= 2
        sum = int(sum)
        n = len(nums)
        dp = [[False for j in range(sum+1)] for i in range(n+1)]
        
        dp[0][0] = True
        for i in range(n+1):
            dp[i][0] = True
        
        for i in range(1,n+1):
            for j in range(1,sum+1):
                dp[i][j] = dp[i-1][j]
                if j >= nums[i-1]:
                    dp[i][j] = dp[i][j] or dp[i-1][j-nums[i-1]]
                    
        return dp[n][sum]