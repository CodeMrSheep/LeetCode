# 数组nums的和的范围在[-sum,sum](sum为所有元素之和)之中，
# 所以我们可以利用动态规划求解，将[-sum,sum]中的值映射到[0,2 * sum]上，
# 则新dp[j + nums[i]] += dp[j], 新dp[j - nums[i]] += dp[j], 
# j 表示元素和，nums[i]表示第i个元素的值。
class Solution(object):
    def findTargetSumWays(self, nums, S):
        """
        :type nums: List[int]
        :type S: int
        :rtype: int
        """
        summ = sum(nums);
        dp = [0]* (2*summ+1)
        if(S > summ or S < -summ or len(nums) == 0):
            return 0
        dp[summ] = 1
        for i in range(len(nums)):
            tmp = [0]*(2*summ+1)
            for j in range(2*summ+1):
                if(dp[j]):
                    tmp[j+nums[i]] += dp[j]
                    tmp[j-nums[i]] += dp[j]
            dp = tmp
        return dp[summ+S]