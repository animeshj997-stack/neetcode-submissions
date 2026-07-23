class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& h) {
        int m=h.size(),n=h[0].size();
        vector<vector<bool>> vis_a(m,vector<bool>(n,0)), vis_p(m,vector<bool>(n,0));
        queue<pair<int,int>> q1,q2;

       for(int i=0;i<m;i++){
        q1.push({i,0});
        q2.push({i,n-1});
       }

       for(int j=0;j<n;j++){
        q1.push({0,j});
        q2.push({m-1,j});
       }

        int di[]={1,-1,0,0};
        int dj[]={0,0,1,-1};

        while(!q1.empty()){
            int i = q1.front().first;
            int j = q1.front().second;
            vis_p[i][j]=1;
            q1.pop();
            for(int k=0;k<4;k++){
                int ni=i+di[k], nj=j+dj[k];
                if(ni>=0 && nj>=0 && ni<m && nj<n && vis_p[ni][nj]==0 && h[i][j]<=h[ni][nj]){
                    q1.push({ni,nj});
                }
            }
        }

        while(!q2.empty()){
            int i = q2.front().first;
            int j = q2.front().second;
            vis_a[i][j]=1;
            q2.pop();
            for(int k=0;k<4;k++){
                int ni=i+di[k], nj=j+dj[k];
                if(ni>=0 && nj>=0 && ni<m && nj<n && vis_a[ni][nj]==0 && h[i][j]<=h[ni][nj]){
                    q2.push({ni,nj});
                }
            }
        }
        vector<vector<int>> ans;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(vis_a[i][j]==1 && vis_p[i][j]==1){
                    ans.push_back({i,j});
                }
            }
        }

        return ans;
    }
};
