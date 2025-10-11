class Solution {
public:
    long long cal(vector<int>& piles, int h){
        int n = piles.size();
        long long sum = 0;
        for (int i = 0; i <n ; i++){
            sum += ceil((double)piles[i]/(double)h);

        }
        return sum;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(),piles.end());
        int ans = 0;
        while(low <= high){
            int mid = low + (high - low)/2;
            long long cc = cal(piles,mid);
            if (cc > h){
                low = mid + 1;
            }
            else{
                ans = mid;
                high = mid -1;
            }
        }
        return ans;
    }
};