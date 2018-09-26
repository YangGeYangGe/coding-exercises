// # https://leetcode.com/problems/partition-equal-subset-sum/description/
// # Given a non-empty array containing only positive integers, find 
// # if the array can be partitioned into two subsets such that 
// # the sum of elements in both subsets is equal.

// # Example 1:

// # Input: [1, 5, 11, 5]

// # Output: true

// # Explanation: The array can be partitioned as [1, 5, 5] and [11].
// # https://leetcode.com/problems/partition-equal-subset-sum/discuss/90592/01-knapsack-detailed-explanation

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int i : nums){
            sum += i;
        }
        if (sum % 2 == 1){
            return false;
        }
        sum /= 2;
        int n = nums.size();
        vector<vector<bool>> dp(n+1, vector<bool>(sum+1, false));
        
        dp[0][0] = true;
        for(int i = 1; i < n+1; ++i){
            dp[i][0] = true;
        }
        
        for(int i = 1; i < n+1; ++i){
            for(int j = 1; j < sum+1; ++j){
                int current_num = nums[i-1];
                dp[i][j] = dp[i-1][j];
                
                if(j >= current_num){
                    dp[i][j] = dp[i][j] || dp[i-1][j - current_num]; 
                }
            }
        }
        return dp[n][sum];
    }
};