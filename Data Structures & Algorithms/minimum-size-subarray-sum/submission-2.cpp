class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ans=nums.size()+1,sum=0,l=0;

        for(int r=0;r<nums.size();r++){
            sum+=nums[r];
            while(sum>=target){
                ans=min(ans,r-l+1);
                sum-=nums[l];
                l++;
            }
        }

        return (ans != nums.size()+1) ? ans : 0;
    }
};