
# https://leetcode.com/problems/container-with-most-water/description/
# Container With Most Water
# Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.

# Example:

# Input: [1,8,6,2,5,4,8,3,7]
# Output: 49

class Solution:
    def maxArea(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        length = len(height)
        if length == 0 or length == 1:
            return 0
        elif length == 2:
            return min(height[0], height[1])
        maxarea = 0
        left = 0
        right = length-1
        
        while left < right:
            maxarea = max(maxarea, (right-left)*min(height[left],height[right]) )
            if height[left] > height[right]:
                right -= 1
            else:
                left += 1
                
        return maxarea