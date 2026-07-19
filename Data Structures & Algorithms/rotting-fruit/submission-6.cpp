class Solution {
   public:
    int orangesRotting(vector<vector<int>>& grid) {
        int ans = 0;
        queue<pair<int, int>> q;
        int cnt_fresh = 0;
        int m = grid.size(), n = grid[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2)
                    q.push({i, j});
                else if (grid[i][j] == 1)
                    cnt_fresh++;
            }
        }

        int di[] = {-1, 1, 0, 0};
        int dj[] = {0, 0, -1, 1};
        cout << cnt_fresh << endl;
        while (!q.empty() && cnt_fresh != 0) {
            int size = q.size();
            while (size) {
                int i = q.front().first;
                int j = q.front().second;
                q.pop();
                for (int k = 0; k < 4; k++) {
                    int ni = i + di[k];
                    int nj = j + dj[k];
                    if (ni >= 0 && nj >= 0 && ni < m && nj < n && grid[ni][nj] == 1) {
                        grid[ni][nj] = 2;
                        cnt_fresh--;
                        q.push({ni, nj});
                    }
                }
                size--;
            }
            ans++;
        }
        cout << cnt_fresh;
        return (cnt_fresh) ? -1 : ans;
    }
};
