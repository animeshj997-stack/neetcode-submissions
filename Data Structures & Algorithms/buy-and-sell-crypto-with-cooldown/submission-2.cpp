class Solution {
public:
    int f(int i, int buy, vector<int> &prices, vector<vector<int>> &dp){
        if(i>=prices.size()) return 0;
        
        if(dp[i][buy]!=-1) return dp[i][buy];
        int take=0,notTake=0;
        if(buy){
            take=-prices[i]+f(i+1,0,prices,dp);
            notTake=f(i+1,1,prices,dp);
        }
        else{
            take=prices[i]+f(i+2,1,prices,dp);
            notTake=f(i+1,0,prices,dp);
        }

        return dp[i][buy]=max(take,notTake);
    } 
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(),vector<int>(2,-1));
        return f(0,1,prices,dp);
    }
};
