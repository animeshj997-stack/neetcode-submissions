class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string,vector<string>> mp;

        for(auto s : strs){
          string temp(26,'0');
          for(auto c : s){
            temp[c-'a']++;
          }
          mp[temp].push_back(s);
        }

        for(auto i : mp){
          ans.push_back(i.second);
        }

        return ans;
    }
};
