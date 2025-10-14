class Solution {
public:
    bool check(vector<int>& pp , long long m, int c){
        int n = pp.size();
        long long sum = 0;
        for (int i = 0; i<n; i++){
            sum += (long long)(sqrt((double)m / (double)pp[i]));

        }
        return sum >= c;
    }
    long long repairCars(vector<int>& ranks, int cars) {
        long long low = 1;
        long long high = 1LL * (*max_element(ranks.begin(), ranks.end())) * (long long)cars * (long long)cars;

        long long res = high;

        while(low <= high){
            long long mid = low + (high - low)/2;
            if(check(ranks,mid,cars)){
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