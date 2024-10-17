class Solution {
    void dfs(int node, vector<vector<int>>&adjls, vector<int>&vis) {
        vis[node]=1;
        for(auto it: adjls[node]) {
            if(!vis[it]) dfs(it,adjls,vis);
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int v= isConnected.size();
        vector<vector<int>>adjls(v);
        for(int i=0; i<isConnected.size(); i++) {
            for(int j=0; j<isConnected[0].size(); j++) {
                if(isConnected[i][j]==1) {
                    adjls[i].push_back(j);
                    adjls[j].push_back(i);
                }
            }
        }

        vector<int> vis(v, 0);;
        int cnt=0;
        //for each node do dfs, and count how many times you had to start over.
        for(int i=0; i<v; i++) {
            if(!vis[i]) {
                cnt++;
                dfs(i,adjls,vis);
            }
        }
        return cnt;
    }
};