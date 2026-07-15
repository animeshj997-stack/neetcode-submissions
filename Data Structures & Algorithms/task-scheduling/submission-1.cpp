class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
         unordered_map<char,int> mp;
         for(auto i : tasks)
              mp[i]++;

          priority_queue<int> pq;
          queue<pair<int,int>> q;
          int time =0;
          for(auto i : mp)
           pq.push(i.second);

          while(!pq.empty() || !q.empty()){
            time++;
            if(!pq.empty()){
               int cnt = pq.top();
               cnt--;
               pq.pop();
                   if(cnt > 0) {
                    q.push({cnt, time + n});
                }
            }

            if(!q.empty() && q.front().second == time){
                    pq.push(q.front().first);
                    q.pop();
            }

          }

          return time;     
    }
};
