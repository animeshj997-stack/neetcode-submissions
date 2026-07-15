class Solution {
public:
    int characterReplacement(string s, int k) {
        int maxf=0,ans=0,j=0;
        unordered_map<char,int> m;
        for(int i=0;i<s.length();i++){
            m[s[i]]++;
            maxf=max(maxf,m[s[i]]);
            while(i-j+1-maxf>k){
                m[s[j]]--;
                j++;
            }
            ans=max(ans,i-j+1);
        } 
        return ans;       
    }
};
