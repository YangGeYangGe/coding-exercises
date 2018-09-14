# Given an array of integers, return indices of the two numbers such that they add up to a specific target.

# You may assume that each input would have exactly one solution, and you may not use the same element twice.

# Example:

# Given nums = [2, 7, 11, 15], target = 9,

# Because nums[0] + nums[1] = 2 + 7 = 9,
# return [0, 1].
# https://leetcode.com/problems/two-sum/description/
class Solution:
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """

        # result = []
        # for i in range(len(nums)-1):
        #     for j in range(i+1, len(nums)):
        #         if nums[i]+nums[j] == target:
        #             result.append(i)
        #             result.append(j)
        #             break
                    
        # return result

        result = []
        dic = {}
        for i in range(len(nums)):
            t = target-nums[i]
            if (t) in dic.values():
                for n, m in dic.items():
                    if t == m:
                        result.append(n)
                        break
                result.append(i)
            dic[i] = nums[i]
        return result