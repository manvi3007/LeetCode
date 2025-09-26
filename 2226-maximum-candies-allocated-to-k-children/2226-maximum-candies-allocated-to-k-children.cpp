class Solution {
public:
    long long count(vector<int>& c, long long p){
        long long sum = 0;
        for (int i = 0; i < c.size();i++){
            sum += c[i]/p;
        }
        return sum;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        int low = 1;
        long long sum = 0;
        int ans = 0;
        for(int i = 0; i < candies.size();i++){
            sum += candies[i];
        }
        if(sum < k){
            return 0;
        }
        long long high = sum/k;
        while(low<=high){
            long long mid = low + (high - low)/2;
            long long pp = count(candies,mid);
            if(pp >= k){
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