#include <vector>
#include <stdlib.h>
#include <iostream>
#include <queue>
using namespace std;
#define MY_RADIX    10
class Solution {
public:
    void printdata(vector<int> data, int n)
    {
        for (int i = 0;i < n;++i)
            cout << data[i] << "    ";
    }

    int maximumGap(vector<int>& nums)
    {
        if (nums.size() < 2) {
            return 0;
        }
        RadixSort(nums);
        int currentMax = nums[1] - nums[0];
        int temp;
        int i;
        for (i = 2; i < nums.size(); i++) {
            temp = nums[i] - nums[i - 1];
            if (temp > currentMax) {
                currentMax = temp;
            }
        }
        return currentMax;
    }

private:
    void RadixSort(vector<int>& nums)
    {
        int radix = MY_RADIX;
        int digits = 10;
        int factor = 1;
        int vecSize = nums.size();
        queue<int> myQueue[MY_RADIX];
        int i, j, k, index;
        for (i = 0; i < digits; i++) {
            for (j = 0; j < vecSize; j++) {
                myQueue[nums[j] / factor % radix].push(nums[j]);
            }
            index = 0;
            for (k = 0; k < MY_RADIX; k++) {
                while (!myQueue[k].empty()) {
                    nums[index++] = myQueue[k].front();
                    myQueue[k].pop();
                }
            }
            factor *= 10;
        }
    }
};

int main(void)
{
    Solution a;
    vector<int> nums{3, 6, 9, 1};
    int result = a.maximumGap(nums);
    a.printdata(nums, nums.size());
    cout << "\n" << result << endl;
    return 0;
}