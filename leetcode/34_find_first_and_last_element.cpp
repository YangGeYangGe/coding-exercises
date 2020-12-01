// https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array/
#include <vector>
#include <stdlib.h>
using namespace std;
/*
// O(n)
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result{-1, -1};
        if (nums.size() == 0) {
            return result;
        }
        int leftIndex = 0;
        int rightIndex = nums.size() - 1;
        int leftFlag = 0;
        int rightFlag = 0;
        while (rightIndex >= leftIndex) {
            if (nums[leftIndex] != target) {
                leftIndex++;
            } else {
                leftFlag = 1;
            }
            if (nums[rightIndex] != target) {
                rightIndex--;
            } else {
                rightFlag = 1;
            }
            if (rightFlag == 1 && leftFlag == 1) {
                break;
            }
        }
        if (rightIndex < leftIndex) {
            return result;
        }
        result[0] = leftIndex;
        result[1] = rightIndex;
        return result;
    }
};
*/
// binary search, O(logn)
class Solution {
public:
    int FindLeftFirst(vector<int>& nums, int target)
    {
        int mid;
        int left = 0;
        int right = nums.size() - 1;
        int ans = -1;
        while (left <= right) {
            mid = (left + right) / 2;
            if (nums[mid] < target) {
                left = mid + 1;
            } else if (nums[mid] == target) {
                right = mid - 1;
                ans = mid;
            } else {
                right = mid - 1;
            }
        }
        return ans;
    }
    int FindRightFirst(vector<int>& nums, int target)
    {
        int mid;
        int left = 0;
        int right = nums.size() - 1;
        int ans = -1;
        while (left <= right) {
            mid = (left + right) / 2;
            if (nums[mid] < target) {
                left = mid + 1;
            } else if (nums[mid] == target) {
                left = mid + 1;
                ans = mid;
            } else {
                right = mid - 1;
            }
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result{-1, -1};
        if (nums.size() == 0) {
            return result;
        }
        
        int leftIndex = FindLeftFirst(nums, target);
        if (leftIndex == -1) {
            return result;
        }
        result[0] = leftIndex;
        result[1] = FindRightFirst(nums, target);
        return result;
    }
};