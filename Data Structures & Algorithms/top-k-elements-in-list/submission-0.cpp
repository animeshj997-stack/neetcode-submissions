class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(auto i : nums)
        mp[i]++;

        priority_queue<pair<int,int>> pq;
        for(auto i : mp){
            pq.push({i.second,i.first});
        }
        
        vector<int> res;
        while(k && !pq.empty()){
            int num = pq.top().second;
            pq.pop();
            res.push_back(num);
            k--;
        }
        return res;
    }
};
