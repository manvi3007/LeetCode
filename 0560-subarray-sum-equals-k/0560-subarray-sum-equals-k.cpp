class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sum = 0 , n = nums.size(), cnt = 0;
        unordered_map<int,int>mp;

        mp[0]=1;

        for (int i = 0; i<n ; i++){
            sum += nums[i];
            int rem = sum - k;
            cnt += mp[rem];
            mp[sum]++;
        }
        return cnt;
    }
};