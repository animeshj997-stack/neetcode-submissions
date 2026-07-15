class Solution {
public:
    int f(int i, int j, vector<int> &nums, vector<vector<int>> &dp){
        if(i==nums.size() || j==nums.size()) return 0; 

        if(dp[i][j+1]!=-1) return dp[i][j+1];
        int take = -1e9;
        if(nums[i]>nums[j] || j==-1){
            take=1+f(i+1,i,nums,dp);
        }
        int notTake = f(i+1,j,nums, dp);

        return dp[i][j+1] = max(take,notTake);
    }

    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return f(0,-1,nums,dp);
    }
};
