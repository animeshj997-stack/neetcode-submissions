class Solution {
public:
    int f(int i, vector<int> &coins, int a, vector<vector<int>> &dp) {
        if(a==0) return 0;
        if(i>=coins.size()) return 1e9;
        if(dp[i][a]!=-1) return dp[i][a];

       int notPick=f(i+1,coins,a,dp);
       int pick = 1e9;
       if(a>=coins[i]){
        pick=1+f(i,coins,a-coins[i],dp);
       }

       return dp[i][a] = min(pick,notPick);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        int ans = f(0,coins,amount,dp);
        if(ans>=1e9) return -1;

        return ans;
    }
};
