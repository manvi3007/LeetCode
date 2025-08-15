class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return subb(nums,k) - subb(nums,k-1);
    }

    int subb(vector<int>& nums, int k){
        int l = 0;
        int r = 0;
        int count = 0;
        unordered_map<int,int>mpp;

        while ( r< nums.size()){
            mpp[nums[r]]++;

            while (mpp.size() > k){
                mpp[nums[l]]--;
                if (mpp[nums[l]] == 0){
                    mpp.erase(nums[l]);
                }
                l++;
            }
            count += r-l+1;
            r++;
        }
        return count;




    }
};