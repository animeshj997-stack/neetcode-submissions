class Solution {
public:
    bool canJump(vector<int>& nums) {
        int l=0,r=0,farthest=0;
        
        for(int i=0;i<nums.size();i++){
            if(farthest<i) return 0;

            farthest=max(farthest,i+nums[i]);

            if(farthest>=nums.size()-1) return 1;
        }

        return 1;
    }
};
