class Solution {
public:
    vector<int> Merge(vector<int> vecA, vector<int> vecB)
    {
        vector<int> result;
        int i;
        int leftIndex = 0;
        int rightIndex = 0;
        int totalSize = vecA.size() + vecB.size();
        for (i = 0; i < totalSize; i++) {
            if (leftIndex >= vecA.size()) {
                result.push_back(vecB[rightIndex++]);
            } else if (rightIndex >= vecB.size()) {
                result.push_back(vecA[leftIndex++]);
            } else if (vecA[leftIndex] > vecB[rightIndex]) {
                result.push_back(vecA[leftIndex++]);
            } else {
                result.push_back(vecB[rightIndex++]);
            }
        }
        return result;
    }

    vector<int> MergeSort(vector<int> nums)
    {
        if (nums.size() < 2) {
            return nums;
        }
        int mid = nums.size() / 2;
        vector<int> left(nums.begin(), nums.begin() + mid);
        vector<int> right(nums.begin() + mid, nums.end());

        return Merge(MergeSort(left), MergeSort(right));
    }

    int findKthLargest(vector<int>& nums, int k) {
        vector<int> ordered = MergeSort(nums);
        return ordered[k - 1];
    }
};