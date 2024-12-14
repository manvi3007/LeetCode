class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int ind = -1;
        int n = nums.size();

        // Step 1: Find the first index `ind` from the right such that nums[ind] < nums[ind + 1]
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                ind = i;
                break;
            }
        }

        // Step 2: If no such index is found, the array is sorted in descending order
        // Reverse it to get the smallest permutation
        if (ind == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }

        // Step 3: Find the smallest element larger than nums[ind] to the right of it
        for (int i = n - 1; i > ind; i--) {
            if (nums[i] > nums[ind]) {
                swap(nums[i], nums[ind]);
                break;
            }
        }

        // Step 4: Reverse the part of the array to the right of `ind`
        reverse(nums.begin() + ind + 1, nums.end());
    }
};
