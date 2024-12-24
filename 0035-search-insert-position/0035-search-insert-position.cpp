class Solution {
public:
    int searchInsert(vector<int>& arr, int k) {
        int n = arr.size();
        int ans = n;
        
        int low = 0;
        int high = n-1;
        while(low<=high){
            int mid = (low + high)/2;
            if (arr[mid ]>= k){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return ans;
    }
};