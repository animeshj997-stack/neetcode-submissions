class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // unordered_map<int,int> mp;
        // for(auto i : nums)
        // mp[i]++;

        // priority_queue<pair<int,int>> pq;
        // for(auto i : mp){
        //     pq.push({i.second,i.first});
        // }
        
        // vector<int> res;
        // while(k && !pq.empty()){
        //     int num = pq.top().second;
        //     pq.pop();
        //     res.push_back(num);
        //     k--;
        // }
        // return res;

        unordered_map<int,int> mp;
        for(auto i : nums)
        mp[i]++;
        
        int n = nums.size();
        vector<vector<int>> f(n+1);
        vector<int> ans;

        for(auto i : mp)
        f[i.second].push_back(i.first);

        for(int i=n;i>=0;i--){
            for(int j=0;j<f[i].size();j++){
                ans.push_back(f[i][j]);
                if(ans.size()==k) return ans; 
            }
        }
        return ans;

    }
};
