class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int high=0;
        for(auto i : piles) high=max(i,high);

        int low=1,res=high;

        while(low<=high) {
          int mid = low+(high-low)/2;
          int temp=0;
          for(int i=0;i<piles.size();i++){
              if(piles[i]%mid==0) temp += (piles[i]/mid);
              else if(piles[i]%mid) temp += (piles[i]/mid)+1;
          }

          if(temp>h)
            low=mid+1;
          else{
            res=min(res,mid);
            high=mid-1;
          }  
        }

        return res;
    }
};
