class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        int left = 0; 
        int right = 0; 
        int total = 0;
        vector<int>ans;
        int diff = 0;
        for (int i = 0; i<n; i++){
            total += nums[i];

        }
        for (int i = 0; i < n ; i++){
            right = total - left - nums[i];
            diff = abs(right-left);
            ans.push_back(diff);
            left += nums[i];

        }
        return ans;
    }
};