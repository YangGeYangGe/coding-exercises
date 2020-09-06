'''
https://leetcode-cn.com/problems/group-anagrams-lcci/submissions/

用一个dictionary，key是排序后的字符串，value是原字符串的数list

'''
class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        dic = {}
        for strEle in strs:
            sortedStr = str(sorted(strEle))
            #print(sortedStr)
            if sortedStr not in dic:
                dic[sortedStr] = [strEle]
            else:
                dic[sortedStr].append(strEle)
        return list(dic.values())