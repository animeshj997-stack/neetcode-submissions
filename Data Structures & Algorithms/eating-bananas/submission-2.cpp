class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxii=piles[0];
        for(auto i : piles){
            maxii=max(maxii,i);
        }
        int res=maxii;
        int low=1,high=maxii;

        while(low<=high){
            int mid = low+(high-low)/2;
            int hrs=0;
            for(int i=0;i<piles.size();i++) {
                if(mid>=piles[i]) hrs++;
                else if(piles[i]%mid==0) hrs+=(piles[i]/mid);
                else hrs+= (piles[i]/mid)+1;
            }

            if(hrs<=h){
                res=min(res,mid);
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }

        return res;
    }
};
