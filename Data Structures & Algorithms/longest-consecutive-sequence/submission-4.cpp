class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;
        if(nums.size()==0) return 0;
        for(auto it : nums){
            st.insert(it);
        }
        int longest=1;
        for(auto it : st){
            if(st.find(it-1)==st.end()){
               int cnt=0;
               int x=it;
               while(st.count(x)){
                cnt++;
                x++;
               }
               longest=max(longest,cnt);
            }
        }

        return longest;
    }
};
