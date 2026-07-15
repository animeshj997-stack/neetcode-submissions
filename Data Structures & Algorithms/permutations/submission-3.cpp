class Solution {
public:
    vector<vector<int>> res;
    void perm(vector<int> &nums, vector<int> &per, vector<bool> &pick){
        if(per.size()==nums.size()){
            res.push_back(per);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(!pick[i]){
                pick[i]=1;
                per.push_back(nums[i]);
                perm(nums,per,pick);
                pick[i]=0;
                per.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> per;
        vector<bool> pick(nums.size(),0);

        perm(nums,per,pick);

        return res;
    }
};
