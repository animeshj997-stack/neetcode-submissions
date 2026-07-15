class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
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
