class Solution {
public:
    int f(int i, int target, vector<int> &nums, vector<vector<int>> &dp){
        if(i==nums.size()){
            return (target==0);
        }

        // if(dp[i][target]!=-1) return dp[i][target];

        int add = f(i+1,target-nums[i],nums,dp);
        int sub = f(i+1,target+nums[i],nums,dp);

        return add+sub;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        vector<vector<int>> dp(nums.size(),vector<int>(target+2000,-1));
        return f(0, target, nums, dp);
    }
};
