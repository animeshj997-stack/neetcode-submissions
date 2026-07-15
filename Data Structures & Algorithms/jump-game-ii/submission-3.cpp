class Solution {
public:
    // int f(int i, vector<int> &nums, vector<int> &dp){
    //     if(i>=nums.size()-1) return 0;
    //     if(dp[i]!=-1) return dp[i];
    //     int res=1e9;
    //     for(int j=i+1;j<=i+nums[i];j++){
    //         res=min(res,1+f(j,nums,dp));
    //     }

    //     return dp[i]=res;
    // }
    int jump(vector<int>& nums) {
        // vector<int> dp(nums.size(),-1);
        // return f(0,nums,dp);
       
       int jump=0,l=0,r=0,farthest=0;

       while(r<nums.size()-1){
           for(int i=l;i<=r;i++){
            farthest=max(farthest,i+nums[i]);
           }
           l=r+1;
           r=farthest;
           jump++;
       }

       return jump;
    }
};
