class Solution {
    int firstOcc(vector<int> arr, int n, int x) {
    int low = 0;
    int high = n - 1;
    int first=-1;

    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == x) {
            first=mid;
            high = mid - 1;
        } 
        else if(arr[mid]>x) high=mid-1;
        else low = mid + 1; 
    }
    return first;
}

    int lastOcc(vector<int> arr, int n, int x) {
    int low = 0;
    int high = n - 1;
    int last=-1;

    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid]==x) {
            last=mid;
            low=mid+1;
        } 
        else if(arr[mid]<x) low=mid+1;
        else high=mid-1;
    }
    return last;
}
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first= firstOcc(nums, nums.size(), target);
        if(first==-1) return {-1,-1};
        int last= lastOcc(nums, nums.size(), target);
        return {first,last};
    }
};