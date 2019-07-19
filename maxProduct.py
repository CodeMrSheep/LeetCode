class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int len = nums.size();
        int mmax = nums[0];
        int mmin = nums[0];
        int res = nums[0];
        for(int i = 1;i<len;i++){
            int mx = mmax,mn=mmin;
            mmax = max(max(mx*nums[i],mn*nums[i]),nums[i]);
            mmin = min(min(mx*nums[i],mn*nums[i]),nums[i]);
            res = max(mmax,res);
        }
        return res;
        
    }
};