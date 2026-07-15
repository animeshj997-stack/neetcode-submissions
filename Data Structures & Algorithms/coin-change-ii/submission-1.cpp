class Solution {
public:
    int count(int i, int target, vector<int> &coins, vector<vector<int>> &dp){
        if(target==0)
         return 1;
        if(target<0 || i>=coins.size())
         return 0; 
        
        if(dp[i][target]!=-1) return dp[i][target];
        int take=0,nottake=0;
        if(target>=coins[i]){
            take=count(i,target-coins[i],coins,dp);
        }
        nottake=count(i+1,target,coins,dp);

        return dp[i][target] = take+nottake;
    }
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size(),vector<int>(amount+1,-1));
        int res = count(0,amount,coins,dp);
        return res;
    }
};
