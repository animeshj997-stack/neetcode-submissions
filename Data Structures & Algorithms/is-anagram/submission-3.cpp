class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> v(26,0);

        for(auto i : s)
          v[i-'a']++;

        for(auto i : t)
          v[i-'a']--;

        for(int i=0;i<26;i++){
            if(v[i]!=0)
             return 0;
        }

        return 1;    
    }
};
