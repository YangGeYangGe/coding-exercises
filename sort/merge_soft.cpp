#include "stdlib.h"
#include <iostream>
#include <vector>
using namespace std;

void PrintVector(vector<int> vec)
{
    for (auto i = vec.begin(); i != vec.end(); i++) {
        cout << *i << ", " ;
    }
    cout << endl;
}

vector<int> Merge(vector<int> vecA, vector<int> vecB)
{
    std::vector<int> result;
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
            result.push_back(vecB[rightIndex++]);
        } else {
            result.push_back(vecA[leftIndex++]);
        }
    }

    return result;
}

vector<int> MergeSort(vector<int> target)
{
    if (target.size() < 2) {
        return target;
    }

    int mid = target.size() / 2;
    vector<int> left(target.begin(), target.begin() + mid);
    vector<int> right(target.begin() + mid, target.end());

    return Merge(MergeSort(left), MergeSort(right));
}

int main(void)
{
    vector<int> a{10, 30, 20, 40, 1, 2, 56, 1, 5};
    vector<int> b = MergeSort(a);

    PrintVector(b);
    return 0;
}