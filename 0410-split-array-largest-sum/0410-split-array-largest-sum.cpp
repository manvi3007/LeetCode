class Solution {
public:
    int subs(vector<int>& num, int j){
        int ment = 1;
        int element = 0;
        int n = num.size();
        for (int i =0;i<n;i++){
            if (num[i]+element <= j){
                element += num[i];
            }
            else {
                ment ++;
                element = num[i];
            }
        }
        return ment;
    }
    int findarr(vector<int>& nus, int n,int m){
        if (m>n){
            return -1;
        }
        int l = nus.size();
        int maxi = INT_MIN;
        int sum =0;
        for (int i = 0;i<n;i++){
            maxi = max(maxi,nus[i]);
            sum += nus[i];

        }
        int low = maxi;
        int high = sum;
        while(low<=high){
            int mid = (low+high)/2;
            int fn = subs(nus,mid);
            if (fn>m){
                low = mid+1;
            }
            else {
                high = mid-1;
            }
        }
        return low;
    }
    int splitArray(vector<int>& nums, int k) {
       return findarr(nums,nums.size(),k);
    }
};