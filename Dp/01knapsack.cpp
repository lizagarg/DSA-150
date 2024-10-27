int knapsackUtil(vector<int>& wt, vector<int>& val, int ind, int W, vector<vector<int>>& dp) {
    if (W == 0 || i<0) return 0;
    
    if (dp[ind][W] != -1) return dp[ind][W];

    int notTaken = knapsackUtil(wt, val, ind - 1, W, dp);
    int taken = 0;
    if (wt[ind] <= W) taken = val[ind] + knapsackUtil(wt, val, ind - 1, W - wt[ind], dp);

    return dp[ind][W] = max(notTaken, taken);
}

int knapsack(vector<int>& wt, vector<int>& val, int n, int W) {
    vector<vector<int>> dp(n, vector<int>(W + 1, -1));
    return knapsackUtil(wt, val, n - 1, W, dp);
}



