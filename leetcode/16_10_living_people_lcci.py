'''
把每年的生存人数都记录下来
然后根据人数还有年份进行排序

https://leetcode-cn.com/problems/living-people-lcci/
'''


class Solution:
    def maxAliveYear(self, birth: List[int], death: List[int]) -> int:
        dic = {}
        for i in range(len(birth)):
            for j in range(birth[i], death[i] + 1):
                if j not in dic:
                    dic[j] = 1
                else:
                    dic[j] += 1
        maxlen, res = 0, 0
        for k, v in dic.items():
            if v > maxlen:
                maxlen = v
                res = k
            elif v == maxlen and res > k:
                res = k
        return res