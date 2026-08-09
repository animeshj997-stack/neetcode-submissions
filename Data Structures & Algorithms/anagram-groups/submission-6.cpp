class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mp;
        vector<vector<string>> res;
        for(auto i : strs){
          string s(26,'0');
          for(auto c : i){
            s[c-'a']++;
          }
          mp[s].push_back(i);
        }

        for(auto i : mp){
            res.push_back(i.second);
        }

        return res;
    }
};
