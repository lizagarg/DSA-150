class Solution {
    int helper(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>&dp) {
        if(i==0) return matrix[0][j];
        if(j<0 || j>=matrix[0].size()) return 1e8;

        if(dp[i][j]!=-1) return dp[i][j];

        int up= matrix[i][j]+helper(i-1,j,matrix,dp);
        int ld= matrix[i][j]+helper(i-1,j-1,matrix,dp);
        int rd= matrix[i][j]+helper(i-1,j+1,matrix,dp);
        return dp[i][j]=min(up,min(ld,rd));
    }
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m= matrix.size();
        int n= matrix[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        int mini=1e8;
        for(int j=0; j<n; j++) {
            mini=min(mini, helper(m-1,j,matrix,dp));
        }
        return mini;
    }
};