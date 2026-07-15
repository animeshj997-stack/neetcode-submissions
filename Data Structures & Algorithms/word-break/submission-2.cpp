class Solution {
public:
    bool f(int i, string ss, string &s, unordered_set<string> set, vector<vector<int>> &dp){
        if(i==s.length()){
            // ss.push_back(s[i]);
           return dp[i][ss.length()] = (set.count(ss)) ? 1 : 0;
        }
    
         if(dp[i][ss.length()]!=-1) return dp[i][ss.length()];  
                ss.push_back(s[i]);
                // cout<<ss<<endl;
           bool take =0;
         if(set.find(ss)!=set.end())
          take = f(i+1,"",s,set,dp);
             
          bool notTake = f(i+1,ss,s,set,dp);

          return dp[i][ss.length()] = take || notTake;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> set;
        for(auto i : wordDict)
          set.insert(i);
        
        int n = s.length();
        set.insert("");
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return f(0,"",s,set,dp);

    }
};
