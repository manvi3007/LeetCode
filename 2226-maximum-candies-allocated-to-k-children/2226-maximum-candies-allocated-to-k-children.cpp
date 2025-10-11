class Solution {
public:
    long long cal (vector<int>& can, int ch){
        int n = can.size();
        long long sum = 0;
        for (int i = 0; i < n ; i++){
            sum += can[i]/ch;
        }
        return sum;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        long long low = 1;
        long long high = *max_element(candies.begin(),candies.end());
        long long ans = 0;
        while(low <= high){
            long long mid = low + (high - low)/2;
            long long cc = cal(candies,mid);
            if(cc >= k){
                ans = mid;
                low = mid +1;
            }
            else{
                high = mid -1;
            }
        }
        return ans;
    }
};