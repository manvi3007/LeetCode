class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = spells.size();
        int m = potions.size();
        sort(potions.begin(), potions.end());
        vector<int> res;

        for (int i = 0; i < n; i++) {
            int low = 0;
            int high = m - 1;
            int ans = m;   // ✅ move inside loop

            while (low <= high) {
                int mid = low + (high - low) / 2;
                if ((long long)spells[i] * potions[mid] >= success) {
                    ans = mid;
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }

            res.push_back(m - ans);
        }

        return res;
    }
};
