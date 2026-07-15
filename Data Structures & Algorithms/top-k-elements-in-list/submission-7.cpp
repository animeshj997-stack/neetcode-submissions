class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(auto i : nums)
        mp[i]++;
        
        int n=nums.size();
        vector<vector<int>> freq(n+1);

        for(auto i : mp){
            freq[i.second].push_back(i.first);
        }
        vector<int> res;

        for(int i=n;i>0;i--){
            for(int j=0;j<freq[i].size();j++){
                res.push_back(freq[i][j]);
            }
            if(res.size()==k) break;
        }

        return res;
    }
};
