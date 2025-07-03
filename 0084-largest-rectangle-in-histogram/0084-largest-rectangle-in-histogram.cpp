class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int maxA = 0;
        int n = heights.size();

        for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[i] < heights[st.top()]) {
                int element = st.top(); st.pop();
                int nse = i;
                int pse = st.empty() ? -1 : st.top();
                maxA = max(maxA, heights[element] * (nse - pse - 1));
            }
            st.push(i);
        }

        
        while (!st.empty()) {
            int element = st.top(); st.pop();
            int nse = n;
            int pse = st.empty() ? -1 : st.top();
            maxA = max(maxA, heights[element] * (nse - pse - 1));
        }

        return maxA;
    }
};