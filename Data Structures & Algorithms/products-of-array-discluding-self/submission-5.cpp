class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // int pdt=1;
        // int zero=0;
        // for(int i=0;i<nums.size();i++){
        //     if(nums[i]==0) {
        //         zero++; continue;
        //     }
        //     pdt*=nums[i];
        // }
        
        // vector<int> output;

        // for(int i=0;i<nums.size();i++){
        //     if(nums[i]!=0){
        //         if(zero==0)
        //           output.push_back(pdt/nums[i]);
        //         else
        //           output.push_back(0);    
        //     }
        //     else{
        //         if(zero>1)
        //           output.push_back(0);
        //         else
        //           output.push_back(pdt);  
        //     }
        // }

        // return output;
        
        int n=nums.size();
        vector<int> suff(nums.size());
        suff[n-1]=1;
        for(int i=n-2;i>=0;i--)
            suff[i]=suff[i+1]*nums[i+1];
        
        vector<int> output;
        int pdt=1;
        for(int i=0;i<n;i++){
            output.push_back(pdt*suff[i]);
            pdt*=nums[i];
        }

        return output;
    }
};
