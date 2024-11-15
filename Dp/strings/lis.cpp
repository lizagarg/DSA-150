class Solution {
    int f(int i,int prev,int n, vector<int>&nums, vector<vector<int>>&dp) {
        //base case
        if(i==n) return 0;
        if(dp[i][prev+1]!=-1) return dp[i][prev+1];
        //not take
        int len= f(i+1,prev,n,nums,dp);
        //take
        if(prev==-1 || nums[i]>nums[prev]) {
            len=max(len,1+f(i+1,i,n,nums,dp));
        }
        return dp[i][prev+1]=len;
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return f(0,-1,n,nums,dp);
    }
};