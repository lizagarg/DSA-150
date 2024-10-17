class Solution {
    void bfs(int i, int j,  vector<vector<int>>&vis, vector<vector<char>>&grid) {
        vis[i][j]=1;
        queue<pair<int,int>>q;
        q.push({i,j});
        int n= grid.size();
        int m= grid[0].size();
        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};

        while(!q.empty()) {
            int i= q.front().first;
            int j= q.front().second;
            q.pop();

            for(int k=0; k<4;k++) {
                int nrow= i+delRow[k];
                int ncol= j+delCol[k];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m 
                && grid[nrow][ncol]=='1' && !vis[nrow][ncol]) {
                    vis[nrow][ncol]=1;
                    q.push({nrow,ncol});
                }
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m= grid[0].size();
        vector<vector<int>>vis(n, vector<int>(m,0));
        int cnt=0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(!vis[i][j] && grid[i][j]=='1') {
                    cnt++;
                    bfs(i,j,vis,grid);
                }
            }
        }
        return cnt;
    }
};


//using  dfs
class Solution {
    void dfs(int i, int j,  vector<vector<int>>&vis, vector<vector<char>>&grid) {
        int n=grid.size();
        int m= grid[0].size();
        if(i<0 || i>=n || j<0 || j>=m || grid[i][j]=='0' || vis[i][j]==1) return;
        vis[i][j]=1;
        dfs(i+1,j,vis,grid);
        dfs(i-1,j,vis,grid);
        dfs(i,j+1,vis,grid);
        dfs(i,j-1,vis,grid);
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m= grid[0].size();
        vector<vector<int>>vis(n, vector<int>(m,0));
        int cnt=0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(!vis[i][j] && grid[i][j]=='1') {
                    cnt++;
                    dfs(i,j,vis,grid);
                }
            }
        }
        return cnt;
    }
};