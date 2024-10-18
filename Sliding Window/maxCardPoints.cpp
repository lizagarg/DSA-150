class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int l=cardPoints.size()-1;
        int r=k-1;
        int lsum=0, rsum=0;
        int maxi=0;

        for(int i=0; i<k; i++) {
            lsum+=cardPoints[i];
        }
        maxi=lsum;

        while(r>=0) {
            lsum=lsum-cardPoints[r];
            rsum=rsum+cardPoints[l];
            r--;
            l--;
            maxi=max(maxi,lsum+rsum);
        }
        return maxi;
    }
};