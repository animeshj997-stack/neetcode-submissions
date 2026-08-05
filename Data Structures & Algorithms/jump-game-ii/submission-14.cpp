class Solution {
public:
    int jump(vector<int>& nums) {
        int l=0, curmax=0, r=0, res=0;
        while(r<nums.size()-1) {
            while(l<=r){
                curmax=max(curmax,nums[l]+l);
                l++;
            }
            l=r;
            r=curmax;
            res++;
        }

        return res;
    }
};
