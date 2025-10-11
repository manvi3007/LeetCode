class Solution {
public:
    int cal (vector<int>&ans, int cap){
        int day = 1;
        int load = 0;
        int n = ans.size();
        for (int i = 0; i<n; i++){
            if(load + ans[i] > cap){
                day++;
                load = ans[i];
            }
            else{
                load += ans[i];
            }
        }
        return day;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(),weights.end());
        int high = accumulate(weights.begin(),weights.end(),0);
        int ans = 0;
        while(low <= high){
            int mid = low + (high - low)/2;
            int d = cal(weights,mid);
            if(d <= days){
                ans = mid;
                high = mid -1;
            }
            else{
                low = mid +1;
            }

        }
        return ans;
    }
};