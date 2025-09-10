class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int rows = grid.size();
        int col = grid[0].size();
        int n = rows * col;
        long long s = 1LL * n * (n+1)/2;
        long long sn = 1LL * n * (n+1)* (2*n+1)/6;
        long long s1 = 0;
        long long s2 = 0;
        for (int i = 0; i < rows ; i++){
            for (int j = 0; j < col ; j++){
                s1 += grid[i][j];
                s2 += grid[i][j] * grid [i][j];
            }
        }
        long long val1 = s1-s;
        long long val2 = s2-sn;
        val2 = val2/val1;
        long long x = (val1+val2)/2;
        long long y = x-val1;

        return {(int)x,(int)y};
    }
};