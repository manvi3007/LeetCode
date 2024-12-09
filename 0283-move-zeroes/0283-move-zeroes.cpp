class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        
        int j = 0; // Pointer for the position to place the next non-zero element
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                swap(nums[i], nums[j]);
                j++;
    }
        }
}
};