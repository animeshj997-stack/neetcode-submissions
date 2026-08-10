class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // int n=nums.size();
        // vector<int> pre(n,1);
        // vector<int> suf(n,1);
        
        // for(int i=1;i<n;i++){
        //     pre[i]=pre[i-1]*nums[i-1];
        // }
        // for(int i=n-2;i>=0;i--){
        //     suf[i]=suf[i+1]*nums[i+1];
        // }
        
        // vector<int> res(n,1);
        // for(int i=0;i<n;i++){
        //     res[i]=pre[i]*suf[i];
        // }

        // return res;

        int pdt=1,zeroes=0;
        int n=nums.size();
        vector<int> res(n,0);

        for(int i=0;i<n;i++){
            if(nums[i]!=0) pdt*=nums[i];
            else zeroes++;
        }

        if(zeroes>1) return res;

        for(int i=0;i<n;i++){
            if(!zeroes){
                res[i]=pdt/nums[i];
            }
            else{
                if(nums[i]==0){
                    res[i]=pdt;
                }
                else{
                    res[i]=0;
                }
            }
        }

        return res;

        
    }
};
