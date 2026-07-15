class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // sort(nums.begin(),nums.end());
        // if(!nums.size()) return 0;
        // int ans = 1,count=1;
        // for(int j=1;j<nums.size();j++){
        //     if(nums[j]-nums[j-1]==1){
        //     count++;
        //     ans=max(ans,count);
        //     }
        //     if(nums[j]-nums[j-1]>1){
        //         count=1;
        //     }
        // }

        // return max(ans,count);
        
        if(!nums.size()) return 0;
        unordered_map<int,int> mp;
        int ans = 1;
        for(int i=0;i<nums.size();i++){
           if(!mp[nums[i]]){
            mp[nums[i]] = mp[nums[i]-1]+mp[nums[i]+1]+1;
            mp[nums[i]-mp[nums[i]-1]]=mp[nums[i]];
            mp[nums[i]+mp[nums[i]+1]]=mp[nums[i]];
            ans=max(ans,mp[nums[i]]);
           }
        }

        return ans;
    }
};
