class Solution {
public:
    long long count(vector<int>& piles,int hh ){
        long long h = 0;
        for (int i = 0; i < piles.size(); i++) {
            h += (piles[i] + hh - 1) / hh;
        }
        return h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        
        int low = 1;
        int n = piles.size();
        int high = *max_element(piles.begin(), piles.end());
        while(low <= high){
            int mid = low + (high - low)/2;
            long long cc = count(piles,mid);
            if (cc <= h){
                high = mid-1;
            }
            else{
                low = mid + 1;
            }
        }
        return low;
    }
};