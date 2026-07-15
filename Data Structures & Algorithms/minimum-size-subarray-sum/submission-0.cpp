class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int j=0,ans=nums.size()+1,sum=0;

        for(int i=0;i<nums.size();i++){
               sum+=nums[i];
               while(sum>=target){
                ans=min(ans,i-j+1);
                sum-=nums[j];
                j++;
               }
        }

        return (ans!=nums.size()+1) ? ans : 0;
    }
};