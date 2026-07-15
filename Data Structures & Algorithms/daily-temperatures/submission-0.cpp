class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& tem) {
        priority_queue< pair<int,int> , vector<pair<int,int>> ,greater<pair<int,int>> > pq;
        int n=tem.size();
        vector<int> res(n,0);

        for(int i=0;i<n;i++){
            while(!pq.empty() && pq.top().first<tem[i]){
                int j = pq.top().second;
                pq.pop();
                res[j]=(i-j);
            }
            pq.push({tem[i],i});
        }

        return res;
    }
};
