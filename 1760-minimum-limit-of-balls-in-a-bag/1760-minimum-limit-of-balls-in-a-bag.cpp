class Solution {
public:
    bool check(vector<int>& n, int cc, int m){
        int sum = 0;
        for (int i = 0; i < n.size();i++){
            sum += (n[i] - 1) / cc;

        }
        if(sum > m) return false;
        return true;
    }
    int minimumSize(vector<int>& nums, int maxOperations) {
        int low = 1;
        int high = *max_element(nums.begin(),nums.end());
        int res = 0;
        while(low < high){
            int mid = low + (high - low)/2;
            if(check(nums,mid,maxOperations)){
                res = mid ;
                high = mid ;
            }
            else{
                low = mid +1;
            }

        }
        return low;
    }
};