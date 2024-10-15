class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int n= g.size()-1;
        int m= s.size()-1;
        int i=0;
        int j=0;
        int count=0;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        while(i<=n && j<=m) {
            if(s[j]>=g[i]) {
                count++;
                i++;
                j++;
            }
            else j++;
        }
        return count;
    }
};