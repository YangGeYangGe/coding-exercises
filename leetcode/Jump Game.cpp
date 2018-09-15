

// # https://leetcode.com/problems/jump-game/description/
// # Given an array of non-negative integers, you are initially positioned at the first index of the array.

// # Each element in the array represents your maximum jump length at that position.

// # Determine if you are able to reach the last index.
// # Input: [2,3,1,1,4]
// # Output: true
// # Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.


class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<bool> l(nums.size(), false);
        l.back() = true;
        
        for(int i = nums.size()-2; i >=0; --i){
            if(nums[i] == 0){
                l[i] = false;
                continue;
            }
            for(int j = i+1; j <i+nums[i]+1; ++j){
                if(l[j] == true){
                    l[i] = true;
                    break;
                }
                    
            }
            
            
        }
        
        return l[0];
    }
};