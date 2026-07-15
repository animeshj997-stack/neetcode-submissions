class Solution {
public:
    int f(int i, vector<int> &coins, int amount, vector<vector<int>> &dp) {
        
        if(i==coins.size()-1){
            if(amount%coins[i]) return 1e9;
            return amount/coins[i];
        }
        
        if(dp[i][amount]!=-1) return dp[i][amount];

        int notPick = f(i+1, coins, amount,dp);
        int pick = INT_MAX;
        if(amount>=coins[i])
          pick = 1 + f(i,coins,amount-coins[i],dp);
        
        return dp[i][amount] = min(pick,notPick); 
    }
    int coinChange(vector<int>& coins, int amount) {
       int n = coins.size();
       vector<vector<int>> dp(n, vector<int>(amount+1,-1));
       int ans = f(0,coins,amount,dp);
      
        return (ans<1e9) ? ans : -1;
    }
};
