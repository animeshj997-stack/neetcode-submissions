class Solution {
public:
    bool f(int i, vector<int> &nums, vector<int> &dp) {
        if(i==nums.size()-1) return 1;

        if(dp[i]!=-1) return dp[i];

        for(int j=i+1;j<=i+nums[i];j++){
            if(f(j,nums,dp)) return dp[i] = 1;
        }

        return dp[i] = 0;
    }
    bool canJump(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        return f(0,nums,dp);
    }
};
