class Solution {
    int solve(int ind,int target,vector<int>&coins,vector<vector<int>>&dp){
        if(ind==0){
            if(target%coins[0]==0) return target/coins[0];
            else return 1e9;
        }

        if(dp[ind][target] != -1) return dp[ind][target];

        int notTake=solve(ind-1,target,coins,dp);
        int take=INT_MAX;
        if(target>=coins[ind]) take=1+solve(ind,target-coins[ind],coins,dp);

        return dp[ind][target]=min(take,notTake);
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        int ans= solve(n-1,amount,coins,dp);
        if(ans>=1e9) return -1;
        else return ans;
    }
};