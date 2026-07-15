class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // vector<vector<string>> res;
        // unordered_map<string,vector<string>> mp;

        // for(auto i : strs){
        //     string s = i;
        //     sort(s.begin(),s.end());
        //     mp[s].push_back(i);
        // }

        // for(auto i : mp){
        //     res.push_back(i.second);
        // }

        // return res;

        vector<vector<string>> res;
        unordered_map<string,vector<string>> mp;
        for(auto s : strs){
            string str(26,'0');
            for(auto i : s){
                str[i-'a']++;
            }
            
            mp[str].push_back(s);     
        }

        for(auto it : mp){
            res.push_back(it.second);
        }

        return res;
    }
};
