class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l=0,ans=0,r=heights.size()-1;;
        while(l<r){
            ans=max(ans,abs(r-l)*min(heights[r],heights[l]));
            if(heights[r]<heights[l])
             r--;
            else
             l++; 
        }
        return ans;
    }
};
