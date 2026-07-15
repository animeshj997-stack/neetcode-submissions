class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // int pdt=1; int zero=0;
        // for(auto i : nums){
        //    if(i){
        //     pdt*=i;
        //    }
        //    else{
        //     zero++;
        //    }
        // }
        
        // vector<int> output;
        // if(zero>1) {
        //     output = vector<int> (nums.size(),0);
        //     return output;
        // }     
        // for(auto i : nums){
        //     if(i){
        //         if(zero) 
        //          output.push_back(0);
        //         else 
        //          output.push_back(pdt/i);
        //     }
        //     else{
        //         output.push_back(pdt);
        //     }
        // }

        // return output;
         
         int n = nums.size();
         vector<int> suf(n,1);
         suf[n-1]=1;
         for(int i = n-2;i>=0;i--){
             suf[i]=suf[i+1]*nums[i+1];
         }
         int pre = 1;
         vector<int> output(n,1);
         for(int i = 0; i < n ; i++){
            output[i] = pre * suf[i];
            pre*=nums[i];
         }

         return output;
          
    }
};
