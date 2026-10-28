class Solution {
public:
    int maxArea(vector<int>& h) {
        int area=0;
        int l=0,r=h.size()-1;
        while(l<r){
            area=max(area,(r-l)*min(h[l],h[r]));
            if(h[l]>h[r]) r--;
            else l++;
        }

        return area;
    }
};
