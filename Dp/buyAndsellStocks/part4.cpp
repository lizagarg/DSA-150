class Solution {
    int f(int i, int buy,int n, vector<int>& prices, vector<vector<vector<int>>>&dp,int cap) {
        if(i==n || cap==0) return 0;

        if(dp[i][cap][buy]!=-1) return dp[i][cap][buy];

        int profit=0;
        if(buy) profit= max(-prices[i]+f(i+1,0,n,prices,dp,cap), f(i+1,1,n,prices,dp,cap));
        else profit=max(prices[i]+f(i+1,1,n,prices,dp,cap-1), f(i+1,0,n,prices,dp,cap));

        return dp[i][cap][buy]=profit;
    }
public:
    int maxProfit(int k, vector<int>& prices) {
        int n= prices.size();
        vector<vector<vector<int>>>dp(n, vector<vector<int>>(k+1, vector<int>(2, -1)));
        return f(0,1,n,prices,dp,k);
    }
};