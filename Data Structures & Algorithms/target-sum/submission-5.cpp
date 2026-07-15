class Solution {
public:
    int sum=0;
    int findTargetSumWays(vector<int>& nums, int target) {
        for(auto i : nums) sum+=i;

        if(abs(target)>sum) return 0;

        vector<vector<int>> dp(nums.size(),vector<int>(sum*2+1,-1));
        return f(0, 0, target, nums, dp);
    }
    
    int f(int i, int total, int target, vector<int> &nums, vector<vector<int>> &dp){
        if(i==nums.size()){
            return (target==total);
        }
        
        if(dp[i][total+sum]!=-1) return dp[i][total+sum];

        int add = f(i+1,total-nums[i],target,nums,dp);
        int sub = f(i+1,total+nums[i],target,nums,dp);

        return dp[i][total+sum] = add+sub;
    }

};
