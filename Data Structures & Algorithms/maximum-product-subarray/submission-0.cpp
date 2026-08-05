class Solution {
public:
    int maxProduct(vector<int>& nums) {
      int curmin=1, curmax=1, res=nums[0];
      for(int i=0;i<nums.size();i++){
        int temp = curmax*nums[i];
        curmax=max(max(curmax*nums[i],curmin*nums[i]),nums[i]);
        curmin=min(min(curmin*nums[i],temp),nums[i]);
        res=max(res,curmax);
      }

      return res;
    }
};
