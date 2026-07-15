class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& tem) {
        // priority_queue< pair<int,int> , vector<pair<int,int>> ,greater<pair<int,int>> > pq;
        int n=tem.size();
        vector<int> res(n,0);
        stack<pair<int,int>> st;
        for(int i=0;i<n;i++){
            while(!st.empty() && st.top().first<tem[i]){
                int j = st.top().second;
                st.pop();
                res[j]=(i-j);
            }
            st.push({tem[i],i});
        }

        return res;
    }
};
