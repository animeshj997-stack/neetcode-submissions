class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
      unordered_map<string,vector<string>> mp;

      for(auto i : strs){
        string s = i;
        string t(26,'0');
        for(int j=0;j<s.length();j++){
            t[s[j]-'a']++;
        }
        mp[t].push_back(s);
      }

      vector<vector<string>> res;
      for(auto i : mp){
        res.push_back(i.second);
      }

      return res;
    }
};
