class Solution {
public:
    const int mod = 1e9 + 7;

    vector<int> nextSmaller(vector<int>& arr) {
        int n = arr.size();
        vector<int> res(n, n);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                res[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        return res;
    }

    vector<int> prevSmaller(vector<int>& arr) {
        int n = arr.size();
        vector<int> res(n, -1);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                res[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        return res;
    }

    vector<int> nextGreater(vector<int>& arr) {
        int n = arr.size();
        vector<int> res(n, n);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] < arr[i]) {
                res[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        return res;
    }

    vector<int> prevGreater(vector<int>& arr) {
        int n = arr.size();
        vector<int> res(n, -1);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] <= arr[i]) {
                res[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        return res;
    }

    long long sumSubarrayMins(vector<int>& arr) {
        vector<int> next = nextSmaller(arr);
        vector<int> prev = prevSmaller(arr);
        long long res = 0;
        for (int i = 0; i < arr.size(); ++i) {
            long long left = i - prev[i];
            long long right = next[i] - i;
            res = (res + arr[i] * left % mod * right % mod) % mod;
        }
        return res;
    }

    long long sumSubarrayMaxs(vector<int>& arr) {
        vector<int> next = nextGreater(arr);
        vector<int> prev = prevGreater(arr);
        long long res = 0;
        for (int i = 0; i < arr.size(); ++i) {
            long long left = i - prev[i];
            long long right = next[i] - i;
            res = (res + arr[i] * left % mod * right % mod) % mod;
        }
        return res;
    }

    long long subArrayRanges(vector<int>& nums) {
        return ((sumSubarrayMaxs(nums) - sumSubarrayMins(nums)) % mod + mod) % mod;
    }
};
