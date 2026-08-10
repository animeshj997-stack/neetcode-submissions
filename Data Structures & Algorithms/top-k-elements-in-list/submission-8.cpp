class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> minHeap;
        unordered_map<int,int> mp;

        for(auto i : nums) mp[i]++;

        vector<int> res;

        for(auto i : mp){
            minHeap.push({i.second,i.first});
            if(minHeap.size()>k){
                minHeap.pop();
            }
        }

        while(!minHeap.empty()){
            res.push_back(minHeap.top().second);
            minHeap.pop();
        }

        return res;
    }
};
