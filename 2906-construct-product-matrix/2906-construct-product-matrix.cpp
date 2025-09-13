class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int MOD = 12345;
        int m = grid[0].size();
        int total = n*m;
        vector<int>res(total,1);
        vector<int>nums;
        nums.reserve(total);

        for (int i = 0; i < n ; i++){
            for (int j = 0; j < m ; j++){
                nums.push_back(grid[i][j] % MOD);
            }
        }

        for ( int i = 1 ; i < total ; i++){
            res[i] = (1LL * res[i-1] * nums[i-1])% MOD;
        }
        int post = 1;
        for (int i = total-1; i >= 0 ; i--){
            res[i] = (1LL * post * res[i]) % MOD;
            post = (1LL * post *nums[i])% MOD;


        }
        int ind = 0;
        vector<vector<int>>ans (n,vector<int>(m));
        for (int i = 0; i < n ; i++){
            for (int j = 0; j < m ; j++){
                ans[i][j] = res[ind++] ;
            }
        }
        return ans;
    }
};