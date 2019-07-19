#
# @lc app=leetcode id=394 lang=python
#
# [394] Decode String
#
class Solution(object):
    def decodeString(self, s):
        """
        :type s: str
        :rtype: str
        """
        stack = []
        stack.append(['',1])
        cnt = ""
        for ch in s:
            if(ch >= '0' and ch <= '9'):
                cnt += ch
            elif(ch == '['):
                stack.append(["",int(cnt)])
                cnt = ""
            elif(ch == ']'):
                st,k = stack.pop()
                stack[-1][0] += st*k
            else:
                stack[-1][0] += ch
        return stack[0][0]

