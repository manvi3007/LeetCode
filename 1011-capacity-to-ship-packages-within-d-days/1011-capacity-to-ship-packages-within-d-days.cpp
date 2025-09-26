class Solution {
public:
    int res (vector<int>& w, int cap){
        int load = 0;
        int days = 1;
        for (int i = 0; i < w.size();i++){
            if(load+w[i] > cap){
                days+=1;
                load=w[i];
            }
            else{
                load += w[i];
            }
        }
        return days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(),weights.end());
        int sum = 0;
        for (int i = 0; i < weights.size();i++){
            sum += weights[i];
        }
        int high = sum;
        while(low<=high){
            int mid = low + (high - low)/2;
            int dd = res(weights,mid);
            if(dd <= days){
                high = mid - 1;
            }
            else{
                low = mid +1;
            }
        }
        return low;
    }
};