class Solution {
public:
    int first(vector<int>& nums, int x){
        int n = nums.size();
        int low = 0;
        int high = nums.size()-1;
        int ans = -1;
        while(low <= high){
            int mid = low+(high-low)/2;
            if (nums[mid]==x){
                ans = mid;
                high = mid-1;
            }
            else if (nums[mid]>x){
                high = mid-1;
            }
            else{
                low = mid+1;
            }

        }
        return ans;
    }
    int low (vector<int>& arr, int x){
        int n = arr.size();
        int low = 0;
        int high = n-1;
        int ans = -1;
        while(low <= high){
            int mid = low+(high-low)/2;
            if(arr[mid]==x){
                ans = mid;
                low = mid+1;
            }
            else if(arr[mid] <x){
                low = mid+1;

            }
            else{
                high = mid-1;
            }
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        return {first(nums,target),low(nums,target)};
    }
};