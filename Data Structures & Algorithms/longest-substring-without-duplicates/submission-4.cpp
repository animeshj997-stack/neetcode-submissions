class Solution {
public:
    int lengthOfLongestSubstring(string s) {
      int j=0, ans=0;
      unordered_map<char,int> m;
      for(int i=0;i<s.length();i++){
            if(m.find(s[i]) != m.end())
               j = max(j,m[s[i]]+1);
            
            ans=max(ans,i-j+1);
            m[s[i]] = i;   
      } 

      return ans;
    }
};