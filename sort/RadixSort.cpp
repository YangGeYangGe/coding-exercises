#include <stdlib.h>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

template<class T>
void RadixSort(T data[], int n)
{
    const int radix = 10, digits = 10;
    int factor = 1;
    int i, j, k, index;
    queue<int> queue[radix];
    for (i = 0; i < digits; ++i, factor *= radix) {
        for (j = 0; j < n; ++j) {
            queue[data[j] / factor % radix].push(data[j]);
        }
        for (k = 0, index = 0; k < radix; ++k) {
            while (!queue[k].empty()) {
                data[index++] = queue[k].front();
                queue[k].pop();
            }
        }
    }
}

template<class T>
void printdata(T data[], int n)
{
	for (int i = 0;i < n;++i)
		cout << data[i] << "    ";
}


int main()
{
	//随机生成不相等的100个数
	int data[100];
	int n = 100;
	for (int i = 0; i <= n - 1; ++i)
		data[i] = i;
	for (int i = n - 1; i >0; --i)
		swap(data[i], data[rand() % i]);
	//基数排序
	RadixSort(data, n);
	printdata(data, n);
	system("pause");
	return 0;
}