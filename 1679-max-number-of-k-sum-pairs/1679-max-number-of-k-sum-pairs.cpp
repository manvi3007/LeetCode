class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int l = 0;
        int r = n-1;
        int cnt = 0;

        while(l<r){
            int sum = nums[l]+nums[r];

            if (sum == k){
                cnt++;
                l++;
                r--;
            }
            else if (sum < k){
                l++;
            }
            else{
                r--;
            }
            
        }
        return cnt ;
    }
};