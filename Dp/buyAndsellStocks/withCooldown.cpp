class Solution {
    int f(int i, int buy,int n, vector<int>& prices, vector<vector<int>>&dp) {
        if(i>=n) return 0;

        if(dp[i][buy]!=-1) return dp[i][buy];

        int profit=0;
        if(buy) profit= max(-prices[i]+f(i+1,0,n,prices,dp), f(i+1,1,n,prices,dp));
        else profit=max(prices[i]+f(i+2,1,n,prices,dp), f(i+1,0,n,prices,dp));

        return dp[i][buy]=profit;
    }
public:
    int maxProfit(vector<int>& prices) {
        int n= prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return f(0,1,n,prices,dp);
    }
};