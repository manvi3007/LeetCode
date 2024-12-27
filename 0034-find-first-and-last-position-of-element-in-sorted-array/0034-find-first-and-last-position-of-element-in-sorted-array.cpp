class Solution {
public:
    int lowerBound(vector<int>& nums, int x) {
        int n = nums.size();
        int low = 0;
        int high = n - 1;
        int ans = -1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (nums[mid] >= x) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }

    int UpperBound(vector<int>& nums, int x) {
        int n = nums.size();
        int low = 0;
        int high = n - 1;
        int ans = -1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (nums[mid] > x) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans == -1 ? n : ans; 
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int lb = lowerBound(nums, target);
        int n = nums.size();

        
        if (lb == -1 || lb >= n || nums[lb] != target) {
            return {-1, -1};
        }

        
        int ub = UpperBound(nums, target) - 1;
        return {lb, ub};
    }
};
