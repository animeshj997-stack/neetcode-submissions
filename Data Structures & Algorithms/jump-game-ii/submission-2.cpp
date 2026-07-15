class Solution {
public:
    int f(int i, vector<int> &nums, vector<int> &dp){
        if(i>=nums.size()-1) return 0;
        if(dp[i]!=-1) return dp[i];
        int res=1e9;
        for(int j=i+1;j<=i+nums[i];j++){
            res=min(res,1+f(j,nums,dp));
        }

        return dp[i]=res;
    }
    int jump(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        return f(0,nums,dp);
       
        // int count=0;
        // int maxii=0;
        // if(nums.size()==1) return 0;
        // for(int i=0;i<nums.size();i++){
        //     if(i>=maxii) count++;
        //     maxii=max(maxii,i+nums[i]);
        //     // if(maxii>=nums.size()-1) return count+1;
        // }

        // return count+1;
    }
};
