class Solution {
    int helper(int i, vector<int>&temp, vector<int>&dp) {
        if(i<0) return 0;

        if(dp[i]!=-1) return dp[i];
        int incl= temp[i]+helper(i-2, temp, dp);
        int excl= helper(i-1, temp, dp);

        return dp[i]= max(incl,excl);
    }
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==0) return 0;
        if(n==1) return nums[0];
        if(n==2) return max(nums[0],nums[1]);

        vector<int>temp1,temp2;
        for(int i=0; i<n; i++) {
            if(i!=0) temp1.push_back(nums[i]);
            if(i!=n-1) temp2.push_back(nums[i]);
        }

        vector<int>dp1(temp1.size(),-1);
        vector<int>dp2(temp2.size(),-1);

        int val1= helper(temp1.size()-1, temp1, dp1);
        int val2= helper(temp2.size()-1, temp2, dp2);

        return max(val1,val2);

    }
};