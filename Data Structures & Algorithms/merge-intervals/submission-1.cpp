class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& in) {
        vector<vector<int>> res;

        sort(in.begin(),in.end());
        
        for(int i=0;i<in.size();i++){
            if(!res.size()){
                res.push_back({in[i][0],in[i][1]});
            }
            else{
                if(res.back()[1]<in[i][0])
                  res.push_back({in[i][0],in[i][1]});
                else
                  res.back()[1]=max(res.back()[1],in[i][1]);  
            }
        }

        return res;
    }
};
