class Solution {
public:
    int f(int i, int j, string &s, string &t, vector<vector<int>> &dp){
        if(i==s.length()){
            return t.length()-j;
        }
        if(j==t.length()){
            return s.length()-i;
        }
        
        if(dp[i][j]!=-1) return dp[i][j];

        if(s[i]==t[j]) return dp[i][j] = f(i+1,j+1,s,t,dp);
    
        return dp[i][j] = 1 + min(f(i+1,j,s,t,dp), min(f(i,j+1,s,t,dp),f(i+1,j+1,s,t,dp)));
        
    }
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.length(),vector<int>(word2.length(),-1));

        return f(0,0,word1, word2,dp);
    }
};
