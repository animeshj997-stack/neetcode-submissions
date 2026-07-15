class Solution {
public:
    int f(int i, vector<int> &coins, int amount, vector<vector<int>> &dp) {
        
        // if(i==coins.size()-1){
        //     if(amount%coins[i]) return 1e9;
        //     return amount/coins[i];
        // }
        if(amount == 0) return 0;
        if(i==coins.size()) return 1e9;
        
        if(dp[i][amount]!=-1) return dp[i][amount];

        int notPick = f(i+1, coins, amount,dp);
        int pick = INT_MAX;
        if(amount>=coins[i])
          pick = 1 + f(i,coins,amount-coins[i],dp);
        
        return dp[i][amount] = min(pick,notPick); 
    }
    int coinChange(vector<int>& coins, int amount) {
       int n = coins.size();
       vector<vector<int>> dp(n, vector<int>(amount+1,0));
     
    //    int ans = f(0,coins,amount,dp);
    for(int i=0;i<=amount;i++){
        if(i%coins[0]==0) dp[0][i]=i/coins[0];
        else dp[0][i]=1e9;
    }

    for(int i=1;i<n;i++){
        for(int a=1;a<=amount;a++){
            int take = 1e9;
            if(coins[i]<=a)
               take= 1+dp[i][a-coins[i]];
           int notTake = dp[i-1][a];

           dp[i][a] = min(take,notTake);
        }
    }
      int ans = dp[n-1][amount];
        return (ans<1e9) ? ans : -1;
    }
};
