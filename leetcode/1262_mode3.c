/*
https://leetcode-cn.com/problems/greatest-sum-divisible-by-three/

dp[i][mode]:
dp[i][0]
dp[i][1]
dp[i][2]
*/
#define MAX(a,b) ((a) > (b) ? (a) : (b))
void Update(int **dp, int *nums, int index)
{
    int modeVal = nums[index] % 3;
    int dp0 = dp[index - 1][0];
    int dp1 = dp[index - 1][1];
    int dp2 = dp[index - 1][2];
    if (modeVal == 0) {
        dp[index][0] = dp0 + nums[index];
        dp[index][1] = (dp1 == 0) ? dp1 : (dp1 + nums[index]);
        dp[index][2] = (dp2 == 0) ? dp2 : (dp2 + nums[index]);
    } else if (modeVal == 1) {
        dp[index][0] = ((dp2 + nums[index]) % 3 == 0) ? MAX(dp0, dp2 + nums[index]) : dp0;
        dp[index][1] = ((dp0 + nums[index]) % 3 == 1) ? MAX(dp1, dp0 + nums[index]) : dp1;
        dp[index][2] = ((dp1 + nums[index]) % 3 == 2) ? MAX(dp2, dp1 + nums[index]) : dp2;
    } else if (modeVal == 2) {
        dp[index][0] = ((dp1 + nums[index]) % 3 == 0) ? MAX(dp0, dp1 + nums[index]) : dp0;
        dp[index][1] = ((dp2 + nums[index]) % 3 == 1) ? MAX(dp1, dp2 + nums[index]) : dp1;
        dp[index][2] = ((dp0 + nums[index]) % 3 == 2) ? MAX(dp2, dp0 + nums[index]) : dp2;
    }
}
int maxSumDivThree(int* nums, int numsSize){
    int **dp = (int **)malloc(sizeof(int) * numsSize * 3);
    int i, modeVal, ret;
    for (i = 0; i < numsSize; i++) {
        dp[i] = (int *)malloc(sizeof(int) * 3);
        dp[i][0] = 0;
        dp[i][1] = 0;
        dp[i][2] = 0;
    }
    modeVal = nums[0] % 3;
    dp[0][modeVal] = nums[0];
    for (i = 1; i < numsSize; i++) {
        Update(dp, nums, i);
    }
    ret = dp[numsSize - 1][0];
    for (i = 0; i < numsSize; i++) {
        free(dp[i]);
    }
    free(dp);
    return ret;
}