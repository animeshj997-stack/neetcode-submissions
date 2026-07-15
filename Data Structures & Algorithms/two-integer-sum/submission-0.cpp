class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;

        for(int i = 0; i<nums.size(); i++){
            if(mp.find(target-nums[i]) != mp.end()){
                int i1 = mp[target-nums[i]];
                int i2 = i;
                return {i1,i2};
            }
            mp[nums[i]]=i;
        }
        return {};
    }
};
