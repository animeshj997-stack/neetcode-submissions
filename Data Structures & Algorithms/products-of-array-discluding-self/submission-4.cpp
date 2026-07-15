class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int pdt=1;
        int zero=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0) {
                zero++; continue;
            }
            pdt*=nums[i];
        }
        
        vector<int> output;

        for(int i=0;i<nums.size();i++){
            if(nums[i]!=0){
                if(zero==0)
                  output.push_back(pdt/nums[i]);
                else
                  output.push_back(0);    
            }
            else{
                if(zero>1)
                  output.push_back(0);
                else
                  output.push_back(pdt);  
            }
        }

        return output;

    }
};
