class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        set<vector<int>> s;
        int n =nums.size();
        for(int i=0;i<nums.size();i++){
            int target=-nums[i];
            int low=i+1, high=n-1;
            while(low<high){
                if(nums[low]+nums[high]==target){
                    s.insert({nums[i],nums[low],nums[high]});
                    low++;
                    high--;
                }
                else if(nums[low]+nums[high]>target){
                    high--;
                }
                else{
                    low++;
                }
            }
        }

        vector<vector<int>> res;

        for(auto it : s){
            res.push_back(it);
        }

        return res;
    }
};
