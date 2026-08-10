class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        // set<vector<int>> s;
        vector<vector<int>> res;
        int n =nums.size();
        for(int i=0;i<nums.size()-2;i++){
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int target=-nums[i];
            int low=i+1, high=n-1;

            while(low<high){
                if(nums[low]+nums[high]==target){
                    res.push_back({nums[i],nums[low],nums[high]});
                    low++;
                    high--;
                    while(low<high && nums[low]==nums[low-1])
                    low++;
                }
                else if(nums[low]+nums[high]>target){
                    high--;
                }
                else{
                    low++;
                }
            }
        }


        // for(auto it : s){
        //     res.push_back(it);
        // }

        return res;
    }
};
