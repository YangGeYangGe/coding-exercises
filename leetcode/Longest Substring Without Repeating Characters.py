# https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
# Given a string, find the length of the longest substring without repeating characters.
# Input: "abcabcbb"
# Output: 3 
# Explanation: The answer is "abc", with the length of 3. 
class Solution:
    def lengthOfLongestSubstring(self,s):
        """
        :type s: str
        :rtype: int
        """
        l = []
        if len(s) == 0 :
            return 0
        if len(s) == 1:
            return 1
        windows_size = 2
        b = True
        for i in range(len(s)):
            b = True
            if i + windows_size > len(s):
                break      
            while(b):
                l.clear()
                tmp_s = s[i:i+windows_size]
                l = list(tmp_s)
                before_size = len(tmp_s)
                after_size = len(list(set(tmp_s)))
                if before_size != after_size:
                    b = False
                else:
                    windows_size += 1
                if i + windows_size > len(s):
                    break
        return windows_size-1
