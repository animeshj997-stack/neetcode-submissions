class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxii=0;
        for(auto i : piles)
         maxii=max(i,maxii);

         int low=1,high=maxii;
         int res=maxii;

         while(low<=high){
            int mid = (low+high)/2;
            int hrs=0;
            for(auto i : piles){
                if(i<=mid) hrs++;
                else if(i%mid==0) hrs+=i/mid;
                else hrs+= i/mid + 1;  
            }

            if(hrs>h){
                low=mid+1;
            }
            else{
                res=min(res,mid);
                high=mid-1;
            }
         }

         return res;
    }
};
