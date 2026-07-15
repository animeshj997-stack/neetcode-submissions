class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
       int ans=0,l=0,n=nums.size(),zero=0;
       for(int r=0;r<n;r++){
         if(nums[r]==0) zero++;
         while(zero>k){
            if(nums[l]==0) zero--;
            l++;
         }
         ans=max(ans,r-l+1);
       }

       return ans;
    }
};