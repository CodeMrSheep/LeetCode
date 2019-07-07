class Solution(object):
    def subsetsWithDup(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        res = [[]]
        re = []
        for i in range(len(nums)):
            l = len(res)
            for j in range(l):
                mid = list(res[j])
                mid.append(nums[i])
                res.append(mid)
        for i in range(len(res)):
            if(res[i]!=[]):
                res[i] = sorted(res[i])
        [re.append(x) for x in res if not x in re]
        return re