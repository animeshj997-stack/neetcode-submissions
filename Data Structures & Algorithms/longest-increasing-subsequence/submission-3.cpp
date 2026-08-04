class Solution {
public:
    int f(int i, int j, vector<int> &nums,vector<vector<int>> &dp){
        if(i==nums.size() || j==nums.size())
          return 0;
        if(dp[i][j+1]!=-1) return dp[i][j+1];
        int take=0;
        int nottake = f(i+1,j,nums,dp);
        if(j==-1 || nums[i]>nums[j]){
            take = 1+f(i+1,i,nums,dp);
        }

        return dp[i][j+1] = max(take,nottake);
    }
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>> dp(nums.size()+1,vector<int>(nums.size()+1,-1));
        return f(0,-1,nums,dp);
    }
};
