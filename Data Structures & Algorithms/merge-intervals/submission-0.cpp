class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& i) {
        // sort(intervals.begin(),intervals.end(),[](pair<int,int> a, pair<int,int> b){
        //       if(a.first==b.first) return 
        // });

        sort(i.begin(),i.end());
        vector<vector<int>> ans;
        ans.push_back(i[0]);
        int last = i[0][1];
        for(int j = 1;j<i.size();j++){
           if(last>=i[j][0]){
            last = max(last,i[j][1]);
            ans[ans.size()-1][1] = last;
           }
           else{
            ans.push_back({i[j][0],i[j][1]});
            last = i[j][1];
           }
        }

        return ans;
    }
};
