class Solution {
public:
    int characterReplacement(string s, int k) {
       int maxf=0, j=0, ans=0;
       unordered_map<char,int> mp;

       for(int i=0;i<s.size();i++){
        mp[s[i]]++;
        maxf=max(maxf,mp[s[i]]);
        if(i-j+1-maxf>k){
            mp[s[j]]--;
            j++;
        }
        ans=max(ans,i-j+1);
       }

       return ans;
    }
};
