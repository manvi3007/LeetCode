class Solution {
public:
    int findMax(vector<int>& piles) {
        int maxi = INT_MIN;
        for (int i = 0; i < piles.size(); i++) {
            maxi = max(maxi, piles[i]); 
        }
        return maxi;
    }

    double TotalHrs(vector<int>& piles, int hrs) {
        double ttl = 0;
        for (int i = 0; i < piles.size(); i++) {
            ttl += (int)ceil((double)piles[i] / (double)hrs);


        }
        return ttl;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = findMax(piles);

        while (low <= high) {
            int mid = low + (high - low) / 2; 
            double tl = TotalHrs(piles, mid);
            if (tl <= h) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return low; 
    }
};
