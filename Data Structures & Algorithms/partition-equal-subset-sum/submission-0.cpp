class Solution {
public:
    bool checkSum(int i, int sum, int target, vector<int>&nums, vector<vector<int>> &dp){
        if(sum==target)
         return 1;

        if(i==nums.size() || sum>target) 
         return 0;

        if(dp[i][sum]!=-1) return dp[i][sum];  

        bool take=0;
        if(sum+nums[i]<=target){
            take = checkSum(i+1,sum+nums[i],target,nums,dp);
        }
        bool notTake=checkSum(i+1,sum,target,nums,dp);

        return dp[i][sum] = take||notTake;
    }
    bool canPartition(vector<int>& nums) {
        int target=0;
        for(auto i : nums)
        target+=i;
        
        if(target%2) return 0;
        vector<vector<int>> dp(nums.size(),vector<int>(target/2+1,-1));

        return checkSum(0,0,target/2,nums,dp);
    }
};
