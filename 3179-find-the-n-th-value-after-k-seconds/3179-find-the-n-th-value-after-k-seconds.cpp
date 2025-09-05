class Solution {
public:
    int valueAfterKSeconds(int n, int k) {
        const int MOD = 1'000'000'007;
        vector<long long> a(n, 1);  
        for (int t = 0; t < k; t++) {
            for (int i = 1; i < n; i++) {
                a[i] = (a[i] + a[i - 1]) % MOD;
            }
        }

        return (int)a[n - 1];
    }
};
