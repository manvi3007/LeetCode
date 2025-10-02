class Solution {
public:
    int count (vector<int>& nums, int k){
        int way = 1;
        int sum = 0;
        for (int i = 0; i < nums.size();i++){
            if(nums[i]+sum <= k){
                sum += nums[i];
            }
            else{
                way++;
                sum = nums[i];
            }
        }
        return way;
    }
    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(),nums.end());
        int high = accumulate(nums.begin(),nums.end(),0);
        while(low<=high){
            int mid = low + (high - low)/2;
            int cuu = count(nums,mid);
            if(cuu > k){
                low = mid +1;
            }
            else{
                high = mid -1;
            }
        }
        return low;
    }
};