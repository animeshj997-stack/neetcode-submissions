class Solution {
public:
    int maxArea(vector<int>& h) {
        int ans=0;
        int n = h.size();
        
        int j=n-1,i=0;
        while(i<j){
            ans = max(min(h[i],h[j])*(j-i),ans);
            if(h[i]>h[j]){
                j--;
            }
            else{
                i++;
            }
        }

        return ans;
    }
};
