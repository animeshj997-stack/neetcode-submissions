class Solution {
public:
    int f(int i, vector<int> &nums, int n, vector<int> &dp){
        if(i>=n) return 0;
        if(dp[i]!=-1) return dp[i];

        int rob = nums[i]+f(i+2,nums,n,dp);
        int notRob = f(i+1,nums,n,dp);

        return dp[i]=max(rob,notRob);
    }
    int rob(vector<int>& nums) {
        if(nums.size()==1) return nums[0];

        int n = nums.size();
        vector<int> dp(n,-1);
        int res1=f(0,nums,n-1,dp);

        dp=vector<int> (n,-1);
        int res2=f(1,nums,n,dp);
        
        return max(res1,res2);
    }
};
