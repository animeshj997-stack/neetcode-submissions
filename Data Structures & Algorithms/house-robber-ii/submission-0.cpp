class Solution {
public:
    int f(int i, vector<int> nums, vector<int> &dp){
        if(i>=nums.size()) return 0;
        if(dp[i]!=-1) return dp[i];

        int rob = nums[i] + f(i+2,nums,dp);
        int notRob = f(i+1,nums,dp);

        return dp[i] = max(rob,notRob);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        vector<int> dp(nums.size(),-1);
        int rob1 = f(1,nums,dp);
        
        dp = vector<int> (n,-1);
        nums.pop_back();
        int rob2 = f(0,nums,dp);
        
        return max(rob1,rob2);
    }
};
