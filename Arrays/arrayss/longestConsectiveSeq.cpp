class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        if(nums.size()==0) return 0;
        int counter=1;
        int maxi=1;
        for(int i=1; i<nums.size(); i++) {
            if(nums[i]==nums[i-1]+1) {
                counter++;
                maxi=max(maxi,counter);
            } else if(nums[i]==nums[i-1]) continue;
            else {
                counter=1;
            }
        }
        return maxi;
    }
};