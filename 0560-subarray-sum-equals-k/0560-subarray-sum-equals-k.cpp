class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mpp;
        int PreSum = 0;
        mpp[0]=1;
        int cnt = 0;
        int n = nums.size();
        for (int i =0;i<n;i++){
            PreSum += nums[i];
            int remove = PreSum - k;
            cnt += mpp[remove];
            mpp[PreSum] += 1;
        }
        return cnt;
    }
};