class Solution {
public:
    // bool f(int i, int open, string &s, vector<vector<int>> &dp){
    //     if(open<0) return 0;
    //     if(i==s.length()) return open==0;
        
    //     if(dp[i][open]!=-1) return dp[i][open];
    //     if(s[i]=='(')
    //      return dp[i][open] = f(i+1,open+1,s,dp);
    //     else if(s[i]==')')
    //      return dp[i][open] = f(i+1,open-1,s,dp); 

    //     return  dp[i][open] = f(i+1,open,s,dp) || f(i+1,open-1,s,dp) || f(i+1,open+1,s,dp);
    // }

    bool checkValidString(string s) {
        // vector<vector<int>> dp(s.length(),vector<int>(s.length(),-1));
        // return f(0,0,s,dp);

        stack<int> st, star;

        for(int i=0;i<s.size();i++){
            if(s[i]==')'){
                if(st.empty() && star.empty())
                   return false;
                else if (!st.empty())
                   st.pop();
                else
                   star.pop();                         
            }
            else if(s[i]=='(')
              st.push(i);
            else
              star.push(i);  
        }
     
       while(!st.empty() && !star.empty()){
        if(st.top()>star.top()){
            return false;
        }
        st.pop(); star.pop();
       }

       return st.empty();
    }
};
