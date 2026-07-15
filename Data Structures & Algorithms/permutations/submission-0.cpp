class Solution {
public:
    vector<vector<int>> res;
    void f(vector<int> &nums, vector<bool> &pick, vector<int> &perm){
        if(perm.size()==nums.size()){
         res.push_back(perm);
         return;
        }

        for(int i=0;i<nums.size();i++){
            if(!pick[i]){
                perm.push_back(nums[i]);
                pick[i]=1;
                f(nums,pick,perm);
                perm.pop_back();
                pick[i]=0;
            }
        } 
        
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> pick(nums.size(),0);
        vector<int> perm;
        f(nums,pick,perm);
        return res;
    }
};
