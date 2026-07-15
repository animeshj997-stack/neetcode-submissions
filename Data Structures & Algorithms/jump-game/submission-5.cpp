class Solution {
public:
    bool canJump(vector<int>& nums) {
        int farthest=0;

        for(int i=0;i<nums.size();i++){
            if(i>farthest) return 0;

            farthest=max(farthest,i+nums[i]);
        }

        return 1;
    }
};
