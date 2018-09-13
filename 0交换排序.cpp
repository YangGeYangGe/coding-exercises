// 长度为n的数组乱序存放着0至n-1. 现在只能进行0与其他数的交换，完成以下函数
/**
 * 交换数组里n和0的位置
 * array: 存储[0-n)的数组
 * len: 数组长度
 * n: 数组里要和0交换的数
 */
extern void swap_with_zero(int* array, int len, int n);
class Solution {
public:
    /**
     * 调用方法swap_with_zero来对array进行排序
     */
    void sort(int* array, int len) {
        int idx_0 = 0;
        for(int i = 0; i<len; ++i){
            if(array[i] == 0){
                idx_0 = i;
            }
        }
        bool sorted = true;
        int not_sorted_idx = 0;
        for(int i = len-1; i >= 0; --i){
            if(array[i] != i){
                sorted = false;
                not_sorted_idx = i;
                break;
            }
        }
        if(!sorted){
            swap_with_zero(array, len,array[not_sorted_idx]);
            swap_with_zero(array, len,not_sorted_idx);
            sort(array,len);
        }
    }
};