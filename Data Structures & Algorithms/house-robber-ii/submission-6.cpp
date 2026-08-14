class Solution {
public:
    int f(int i, vector<int> &nums, vector<int> &dp, int n){
        if(i>=n) return 0;
        if(dp[i]!=-1) return dp[i];
        
        int rob = nums[i] + f(i+2,nums,dp,n);
        int notrob = f(i+1,nums,dp,n);

        return dp[i] = max(rob,notrob);
    }

    int rob(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        vector<int> dp(nums.size(),-1);
        int m1 = f(1,nums,dp,nums.size());
        dp=vector<int> (nums.size(),-1);
        int m2 = f(0,nums,dp,nums.size()-1);

        return max(m1,m2);
    }
};