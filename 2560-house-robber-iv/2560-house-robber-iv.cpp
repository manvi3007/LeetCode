class Solution {
public:
    bool check(vector<int>& arr, int cap ,int k){
        int n = arr.size();
        int count = 0;
        int i = 0;
        while(i<n){
            if (arr[i]<=cap){
                count++;
                i += 2;
            }
            else {
                i ++;
            }
            if(count == k){
                break;
            }

        }
            
        
        return count >= k;
    }
    int minCapability(vector<int>& nums, int k) {
        int low = *min_element(nums.begin(),nums.end());
        int high = *max_element(nums.begin(),nums.end());
        int res = 0;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(check(nums,mid,k)){
                res = mid;
                high = mid -1;
            }
            else{
                low = mid +1;
            }
        }
        return res;
    }
};