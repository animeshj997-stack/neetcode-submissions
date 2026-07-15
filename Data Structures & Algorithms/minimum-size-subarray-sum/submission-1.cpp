class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        // int n=nums.size(), res=n+1;
        // for(int i=0;i<n;i++){
        //     int sum=0;
        //     for(int j=i;j<n;j++){
        //       sum+=nums[j];
        //       if(sum>=target){ res=min(res,j-i+1); break;}
        //     }
        // }

        // return (res!=n+1) ? res : 0;
        
        int j=0,sum=0,n=nums.size(),ans=n+1;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            while(sum>=target && j<n){
                ans=min(ans,i-j+1);
                sum-=nums[j];
                j++;
            }
        }

        return (ans==n+1) ? 0 : ans;

    }
};