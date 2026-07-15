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
            sort(nums.begin(),nums.end());
            return;
        }
        int x=n;
        for(int i = n-1;i>idx;i--){
            if( nums[i]>nums[idx] && (x==n || nums[i]<nums[x]) ){
                x=i;
            }
        }

        if(x!=101){
            swap(nums[x],nums[idx]);
        }

        reverse(nums.begin()+idx+1,nums.end());
    }
};