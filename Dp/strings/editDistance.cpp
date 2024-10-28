class Solution {
    int f(int i,int j,string s1,string s2,vector<vector<int>> &dp) {
        if(i<0) return j+1;
        if(j<0) return i+1;

        if(dp[i][j]!=-1) return dp[i][j];

        if(s1[i]==s2[j]) return dp[i][j]=0+f(i-1,j-1,s1,s2,dp);
        //insertion,del,replace
        else return dp[i][j]= min(1+f(i,j-1,s1,s2,dp), 
                    min(1+f(i-1,j,s1,s2,dp),1+f(i-1,j-1,s1,s2,dp)));
    }
    public:
    int minDistance(string word1, string word2) {
        int m=word1.size();
        int n=word2.size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return f(m-1,n-1,word1,word2,dp);
    }
};