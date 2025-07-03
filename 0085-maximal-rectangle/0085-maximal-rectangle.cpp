class Solution {
public:
    int histo(vector<int> hist) {
        int n = hist.size();
        int maxA = 0;
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && hist[i] < hist[st.top()]) {
                int elem = st.top(); st.pop();
                int pse = st.empty() ? -1 : st.top();
                int nse = i;
                maxA = max(maxA, (nse - pse - 1) * hist[elem]);
            }
            st.push(i);
        }

        while (!st.empty()) {
            int elem = st.top(); st.pop();
            int pse = st.empty() ? -1 : st.top();
            int nse = n;
            maxA = max(maxA, (nse - pse - 1) * hist[elem]);
        }

        return maxA;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;
        
        int n = matrix.size();
        int m = matrix[0].size();
        int maxA = 0;
        vector<vector<int>> Psum(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == '1') {
                    Psum[i][j] = (i == 0 ? 1 : Psum[i-1][j] + 1);
                } else {
                    Psum[i][j] = 0;
                }
            }
            maxA = max(maxA, histo(Psum[i]));
        }

        return maxA;
    }
};
