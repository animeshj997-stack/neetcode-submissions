class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& in) {
        sort(in.begin(),in.end());
        int res=0;
        int prevEnd=in[0][1];

        for(int i=1;i<in.size();i++){
          int start = in[i][0];
          int end = in[i][1];
          if(prevEnd > start){
            prevEnd=min(prevEnd,end);
            res++;
          }
          else{
            prevEnd=end;
          }
        }
        return res;
    }
};
