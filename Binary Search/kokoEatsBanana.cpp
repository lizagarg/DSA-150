class Solution {
    int findMax(vector<int>&piles) {
        int maxi=INT_MIN;
        for(int i=0; i<piles.size(); i++) {
            maxi=max(maxi,piles[i]);
        }
        return maxi;
    }

    long long calc(vector<int>&piles, int hourly) {
        long long total=0;
        for(int i=0; i<piles.size(); i++) {
            total+=ceil((double)piles[i]/(double)hourly);
        }
        return total;
    }

public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1;
        int high=findMax(piles);
        int ans=0;
        while(low<=high) {
            int mid=(high+low)/2;
            long long total= calc(piles,mid);
            if(total<=h) {
                high=mid-1;
                ans=mid;
            }
            else low=mid+1;
        }
        return ans;
    }
};


//shorter version
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l=1;
        int r=*max_element(piles.begin(),piles.end());
        int ans=0;

        while(l<=r){
            int mid=l+(r-l)/2;
            long long total=0;
            for(int num:piles){
                total += ceil((double)num/(double)mid);
            }
            if(total<=h) {
                r=mid-1;
                ans=mid;
            } else l=mid+1;
        }
        return ans;
    }
};