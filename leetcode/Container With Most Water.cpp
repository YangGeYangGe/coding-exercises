
// # https://leetcode.com/problems/container-with-most-water/description/
// # Container With Most Water
// # Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.

// # Example:

// # Input: [1,8,6,2,5,4,8,3,7]
// # Output: 49


class Solution {
public:
    int maxArea(vector<int>& height) {
        int length = height.size();
        if(length == 0 || length == 1){
            return 0;
        }else if (length == 2){
            return min(height[0], height[1]);
            
        }
        
        int maxarea = 0, right = height.size()-1, left = 0;
        while(left < right){
            maxarea = max(maxarea, min(height[left], height[right])*(right-left));
            if(height[left] > height[right]){
                right--;
            }else{
                left++;
            }
        }
        return maxarea;
    }
};