class Solution {
    int helper(int i, int j, string &text1, string &text2, vector<vector<int>>&dp) {
        if(i<0 || j<0) return 0;

        if(dp[i][j]!=-1) return dp[i][j];
        //match
        if(text1[i]==text2[j]) return dp[i][j]=1+helper(i-1,j-1,text1,text2,dp);

        return dp[i][j]=max(helper(i-1,j,text1,text2,dp),helper(i,j-1,text1,text2,dp));
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n= text1.size();
        int m= text2.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return helper(n-1,m-1,text1, text2,dp);
    }
};

/*
if match then -> return 1+f(i-1,j-1);
return max(f(i-1,j), f(i,j-1))
*/