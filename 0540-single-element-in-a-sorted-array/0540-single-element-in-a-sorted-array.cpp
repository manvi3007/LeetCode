class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int low = 0;
        int high = nums.size()-1;
        while(low <= high){
            int mid = low + (high - low)/2;
           if ((mid - 1 < 0 || nums[mid - 1] != nums[mid]) &&
    (mid + 1 == nums.size() || nums[mid] != nums[mid + 1])) {
    return nums[mid];
}                int left = (mid-1>=0 && nums[mid]==nums[mid-1])?mid-1 : mid;
            if(left % 2 ==1){
                high = mid -1;
            }
            else{
                low = mid +1;
            }

            }
            return -1;
            
        }
    
    
};