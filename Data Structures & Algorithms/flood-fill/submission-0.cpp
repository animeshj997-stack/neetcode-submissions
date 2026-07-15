class Solution {
public:
    void dfs(vector<vector<int>>& image, int i, int j, int color, int stClr,int m, int n){
        vector<int> di={-1,1,0,0};
        vector<int> dj={0,0,-1,1};

        for(int k=0;k<4;k++){
            int newi=i+di[k];
            int newj=j+dj[k];
            if(newi<m && newj<n && newi>=0 && newj>=0 && image[newi][newj]==stClr && image[newi][newj]!=color){
                image[newi][newj]=color;
                dfs(image,newi,newj,color,stClr,m,n);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int stClr=image[sr][sc];
        int m = image.size(),n=image[0].size();
        image[sr][sc]=color;
        dfs(image,sr,sc,color,stClr,m,n);
        return image;
    }
};