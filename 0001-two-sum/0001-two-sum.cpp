class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> seen; // Map to store {value: index}
        
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];

            // Check if the complement exists in the map
            if (seen.find(complement) != seen.end()) {
                return {seen[complement], i}; // Return original indices
            }

            // Store the current number with its index
            seen[nums[i]] = i;
        }

        return {}; // No solution found (though the problem guarantees one solution)
    }
};
