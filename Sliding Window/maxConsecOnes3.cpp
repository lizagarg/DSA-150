class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l=0, r=0;
        int n=nums.size();
        int maxi=0;
        int zeroes=0;
        while(r<n) {
            if(nums[r]==0) {
                zeroes++;
            }
            if(zeroes>k) {
                while(zeroes>k) {
                    if(nums[l]==0) zeroes--;
                    l++;
                }
            }
            maxi=max(maxi,r-l+1);
            r++;
        }
        return maxi;
    }
};