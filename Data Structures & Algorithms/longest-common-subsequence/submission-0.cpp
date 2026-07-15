class Solution {
public:
    int f(int i, int j, string t1, string t2, vector<vector<int>> &dp){
        if(i==t1.length() || j== t2.length()) return 0;
        
        if(dp[i][j]!=-1) return dp[i][j];
        int pick = -1e9;
        if(t1[i]==t2[j]){
            pick = 1+f(i+1,j+1,t1,t2,dp);
        }

        int notPick = max(f(i+1,j,t1,t2,dp),f(i,j+1,t1,t2,dp));

        return dp[i][j]=max(pick,notPick);
    }

    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.length(),m=text2.length();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        return f(0,0,text1,text2,dp);
    }
};
