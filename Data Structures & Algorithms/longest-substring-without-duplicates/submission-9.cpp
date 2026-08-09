class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans=0,l=0;
        unordered_map<char,int> mp;
        for(int i=0;i<s.length();i++){
            if(mp.count(s[i])){
                l=max(l,mp[s[i]]+1);
            }
            ans=max(ans,i-l+1);
            mp[s[i]]=i;
        }

        return ans;
    }
};
