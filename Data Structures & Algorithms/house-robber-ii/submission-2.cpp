class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        vector<vector<int>> dp(nums.size(),vector<int>(2,-1));
        return max(dfs(0, true, nums,dp), dfs(1, false, nums,dp));
    }

private:
    int dfs(int i, bool flag, vector<int>& nums, vector<vector<int>> &dp) {
        if (i >= nums.size() || (flag && i == nums.size() - 1))
            return 0;
         
        if(dp[i][flag]!=-1) return dp[i][flag]; 
        return dp[i][flag] = max(dfs(i + 1, flag, nums,dp),
                   nums[i] + dfs(i + 2, flag, nums,dp));
    }
};