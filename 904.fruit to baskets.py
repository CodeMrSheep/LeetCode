import collections
class Solution(object):
    def __init__(self):
        self.cnt = collections.defaultdict(int)
    def totalFruit(self,tree):
        left,right = 0,0
        res = 0
        while(right < len(tree)):
            self.cnt[tree[right]] += 1
            while(len(self.cnt) > 2):
                self.cnt[tree[left]] -= 1
                if self.cnt[tree[left]] == 0:
                    del self.cnt[tree[left]]
                left += 1
            res = max(res,right-left+1)
            right += 1
        return res
if __name__ == "__main__":
    Total = Solution()
    input = [1,2,3,2,2]
    print(Total.totalFruit(input),Total.cnt)