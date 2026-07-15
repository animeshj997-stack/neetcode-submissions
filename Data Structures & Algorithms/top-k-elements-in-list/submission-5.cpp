class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // unordered_map<int,int> cnt;
        // for(auto i : nums)
        // cnt[i]++;

        // priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

        // for(auto it : cnt){
        //     pq.push({it.second,it.first});
        //     if(pq.size()>k)
        //     pq.pop();
        // }
        
        // vector<int> res;
        // while(!pq.empty()){
        //     res.push_back(pq.top().second);
        //     pq.pop();
        // }

        // return res;

        int n = nums.size();
        vector<vector<int>> freq(n+1);
        unordered_map<int,int> mp;
        for(auto i : nums)
        mp[i]++;

        for(auto it : mp)
        freq[it.second].push_back(it.first);

        vector<int> res;
        for(int i=n;i>=0;i--){
            for(int j=0;j<freq[i].size();j++){
                res.push_back(freq[i][j]);
                if(res.size()==k) return res;
            }
        }
        return res;
    }
};
