class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int idx=-1, n = nums.size();
        for(int i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                idx=i;break;
            }
        }
        
        if(idx==-1){
            reverse(nums.begin()+idx+1,nums.end());
            return;
        }

        int x=n-1;
        while(nums[idx]>=nums[x]){
            x--;
        }
        swap(nums[x],nums[idx]);

        reverse(nums.begin()+idx+1,nums.end());
    }
};