class Solution {
public:
    int possible (vector<int>& bloomDay, int day, int m, int k){
        int n = bloomDay.size();
        int count = 0;
        int booke = 0;
        for (int i =0;i<n;i++){
            if (bloomDay[i]<=day){
                count ++;
            }
            else {
                booke += (count/k);
                count = 0;
            }}
            booke +=  (count/k);
        
        
        return booke>=m;

    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        long long val = 1LL *m*k;
        if (n < val){
            return -1;
        }
        int mini = INT_MAX;
        int maxi = INT_MIN;
        int ans = -1;
        for (int i =0;i<n;i++){
            mini = min (mini,bloomDay[i]);
            maxi = max (maxi,bloomDay[i]);
        }
        int low = mini;
        int high = maxi;
        while(low<=high){
            int mid = (low+high)/2;
            if (possible(bloomDay,mid,m,k)){
                ans = mid;
                high = mid -1;
            }
            else {
                low = mid+1;
            }
        }
        return ans;
    }
};