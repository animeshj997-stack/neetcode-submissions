class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int sum=0;
        int res=0;
        // mp[0]=1;
        for(int i = 0;i<nums.size();i++){
                      mp[sum]++;

             sum+=nums[i];
             if(mp.count(sum-k))
              res+=mp[sum-k];
        }

        return res;
    }
};