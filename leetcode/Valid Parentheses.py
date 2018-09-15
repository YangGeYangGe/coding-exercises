# https://leetcode.com/problems/valid-parentheses/description/

# Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

# An input string is valid if:

# Open brackets must be closed by the same type of brackets.
# Open brackets must be closed in the correct order.
# Note that an empty string is also considered valid.

# Example 1:

# Input: "()"
# Output: true
class Solution:
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
        l = []
        for i in range(len(s)):
            if s[i] == "(":
                l.append(")")
            elif s[i] == "[":
                l.append("]")
            elif s[i] == "{":
                l.append("}")
            elif len(l) == 0 or l.pop() != s[i]:
                return False
        return len(l) == 0