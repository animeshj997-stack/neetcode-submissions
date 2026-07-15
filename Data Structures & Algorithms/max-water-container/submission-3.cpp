class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l=0,r=heights.size()-1,ans=0;

        while(l<r){
            int h = min(heights[l],heights[r]);
            ans=max(ans,(r-l)*h);
            if(heights[l]>heights[r])
            r--;
            else
            l++;
        }

        return ans;
    }
};
