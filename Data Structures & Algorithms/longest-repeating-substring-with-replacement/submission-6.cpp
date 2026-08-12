class Solution {
public:
    int characterReplacement(string s, int k) {
        int maxf=0,l=0;
        unordered_map<char,int> mp;
        int ans=0;
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
            maxf=max(maxf,mp[s[i]]);
            while(i-l-maxf+1>k){
                mp[s[l]]--;
                l++;
            }
            ans=max(ans,i-l+1);
        }

        return ans;
    }
};
