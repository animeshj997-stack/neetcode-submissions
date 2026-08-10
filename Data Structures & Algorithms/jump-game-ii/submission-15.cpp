class Solution {
public:
    int jump(vector<int>& nums) {
        int res=0,l=0,r=0,farthest=0;

        while(r<nums.size()-1) {
            while(l<=r) {
                farthest=max(farthest,l+nums[l]);
                l++;
            }
            r=farthest;
            res++;
        }
        return res;
    }
};
