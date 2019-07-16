# Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.
# [
#      [2],
#     [3,4],
#    [6,5,7],
#   [4,1,8,3]
# ]
class Solution(object):
    def minimumTotal(self, triangle):
        """
        :type triangle: List[List[int]]
        :rtype: int
        """
        result = 0
        n = len(triangle)
        dp = [0]*(n+1)
        for i in range(n-1,-1,-1):
            for j in range(0,i+1):
                dp[j] = min(dp[j],dp[j+1])+triangle[i][j];
        return dp[0]