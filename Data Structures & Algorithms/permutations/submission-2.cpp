class Solution {
public:
    void backTrack(int i, vector<int> &nums, vector<int> &per, vector<bool> &pick, vector<vector<int>> &res){
        if(per.size()==nums.size()){
            res.push_back(per);
            return;
        }

        for(int j=0;j<nums.size();j++){
            if(pick[j]==0){
                per.push_back(nums[j]);
                pick[j]=1;
                backTrack(j,nums,per,pick,res);
                pick[j]=0;
                per.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> per;
        vector<bool> pick(nums.size(),0);
        vector<vector<int>> res;
        backTrack(0,nums,per,pick,res);
        return res;
    }
};
