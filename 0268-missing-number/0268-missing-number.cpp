class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        int tsum = 0;
        int dsum = 0;

        for (int i = 0; i<n ; i++){
            tsum += nums[i];

            
        }
        sum = n*(n+1)/2;
        return sum - tsum;
        
    }
};