class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
        stack<int> st;
        int n = arr.size();
        vector<int> pse(n);
        for(int i=0;i<n;i++){
              while(!st.empty() && arr[i]<=arr[st.top()]){
                st.pop();
              }
              if(st.empty()) pse[i]=-1;
              else pse[i]=st.top();
              st.push(i);
        }
        
        while(!st.empty()) st.pop();
        for(auto i : pse) cout<<i<<" ";
        vector<int> nse(n);

        for(int i=n-1;i>=0;i--){
          while(!st.empty() && arr[i]<=arr[st.top()]){
            st.pop();
          }
          if(st.empty()) nse[i]=n;
          else nse[i]=st.top();
          st.push(i);
        }
        cout<<endl;
        for(auto i : nse) cout<<i<<" ";
        int maxii=0;
        for(int i=0;i<n;i++){
            int area = arr[i] * (nse[i]-pse[i]-1);
            maxii=max(area,maxii);
        }
        return maxii;

    }
};
