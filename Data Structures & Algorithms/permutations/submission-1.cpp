class Solution {
public:
    void f(vector<int> &nums, vector<int> &per, vector<int> &pick, vector<vector<int>> &res){
        if(per.size()==nums.size()){
            res.push_back(per);
            return;
        }

        for(int i=0;i<nums.size();i++){
            if(pick[i]==0){
               pick[i]=1;
               per.push_back(nums[i]);
               f(nums,per,pick,res);
               per.pop_back();
               pick[i]=0; 
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
       vector<int> per;
       vector<int> pick(nums.size(),0);
       vector<vector<int>> res;
       f(nums,per,pick,res);
       return res;
    }
};
