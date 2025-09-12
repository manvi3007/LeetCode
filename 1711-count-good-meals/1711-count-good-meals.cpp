class Solution {
public:
    int countPairs(vector<int>& deliciousness) {
        const int MOD = 1e9 + 7;  

        unordered_map<int,long long> mp;
        int n = deliciousness.size();
        long long ans = 0;

        for (int i = 0; i < n ; i++){
            int x = deliciousness[i];
            for (int p = 1; p <= (1<<22); p<<=1){
                int y = p - x;
                if(mp.count(y)){
                    ans = (ans + mp[y]) % MOD;
                }
                

            }
            mp[x]++;
        }
        return ans;
    }
};