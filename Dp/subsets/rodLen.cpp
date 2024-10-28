class Solution{
    int f(int i,int N, int price[],vector<vector<int>>& dp) {
       if(i==0) return price[0]*N;

       if(dp[i][N]!=-1) return dp[i][N];

       int notTake=f(i-1,N,price,dp);
       int take=-1e9;
       if(N>=(i+1))
       take=price[i]+f(i,N-(i+1),price,dp);

       return dp[i][N]=max(take,notTake);
    }
  public:
    int cutRod(int price[], int n) {
       vector<vector<int>> dp(n,vector<int>(n+1,-1));
       return f(n-1, n, price, dp);
    }
};

