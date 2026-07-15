class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int pdt=1; int zero=0;
        for(auto i : nums){
           if(i){
            pdt*=i;
           }
           else{
            zero++;
           }
        }
        
        vector<int> output;
        if(zero>1) {
            output = vector<int> (nums.size(),0);
            return output;
        }     
        for(auto i : nums){
            if(i){
                if(zero) 
                 output.push_back(0);
                else 
                 output.push_back(pdt/i);
            }
            else{
                output.push_back(pdt);
            }
        }

        return output;
         
          
    }
};
