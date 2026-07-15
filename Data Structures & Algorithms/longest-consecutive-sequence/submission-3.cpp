class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        if(!nums.size()) return 0;
        int ans = 1,count=1;
        for(int j=1;j<nums.size();j++){
            if(nums[j]-nums[j-1]==1){
            count++;
            ans=max(ans,count);
            }
            if(nums[j]-nums[j-1]>1){
                count=1;
            }
        }

        return max(ans,count);


        
    }
};
