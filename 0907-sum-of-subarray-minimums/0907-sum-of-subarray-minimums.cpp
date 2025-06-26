class Solution {
public:
    vector<int> FindNse(vector<int>& arr) {
        int n = arr.size();
        stack<int> st;
        vector<int> nse(n, n); 

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            if (!st.empty()) {
                nse[i] = st.top();
            }
            st.push(i); 
        }
        return nse;
    }

    vector<int> FindPse(vector<int>& arr) {
        int n = arr.size();
        vector<int> pse(n, -1); 
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }
            if (!st.empty()) {
                pse[i] = st.top();
            }
            st.push(i); 
        }
        return pse;
    }

    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> nse = FindNse(arr);
        vector<int> pse = FindPse(arr);
        int mod = 1e9 + 7;
        long long total = 0;

        for (int i = 0; i < n; i++) {
            long long left = i - pse[i];
            long long right = nse[i] - i;
            total = (total + left * right % mod * arr[i] % mod) % mod;
        }
        return total;
    }
};
