class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        stack<char> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && st.top() > num[i] && k > 0) {
                st.pop();
                k--;
            }
            st.push(num[i]);
        }

        while (k > 0 && !st.empty()) {
            st.pop();
            k--;
        }

        if (st.empty()) return "0";

        string result = "";
        while (!st.empty()) {
            result += st.top();
            st.pop();
        }

        reverse(result.begin(), result.end());

        int i = 0;
        while (i < result.size() && result[i] == '0') {
            i++;
        }
        result = result.substr(i);

        if (result.empty()) return "0";
        return result;
    }
};
