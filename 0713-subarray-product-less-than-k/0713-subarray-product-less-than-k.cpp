class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1){
            return 0 ;
        }
        int l = 0 , r = 0;
        int n = nums.size();
        int count = 0;
        long long product = 1;

       

        for (r = 0 ; r < n ; r++){
            product *= nums[r];

            while (product >= k){
                product /= nums[l];
                l++;
            }
            count += (r-l+1);

        }
        return count ; 
    }
};