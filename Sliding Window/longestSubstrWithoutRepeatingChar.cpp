class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLength = 0;
        int l = 0;
        int r= 0;
        unordered_map<char, int> mp;

        while(r<s.length()) {
            if(mp.find(s[r]) != mp.end() && mp[s[r]] >= l) {
                // in the map and in the range
                l=mp[s[r]]+1;
            }
            maxLength = max(maxLength, r-l+1);
            mp[s[r]]=r;
            r++;
        }
        return maxLength; 
    }
};