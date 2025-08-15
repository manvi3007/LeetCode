class Solution {
public:
    string minWindow(string s, string t) {
        int l = 0, r = 0, count = 0;
        int minlen = INT_MAX, sInd = -1;
        int n = s.size(), m = t.size();
        unordered_map<char,int> mpp;

        for (int i = 0; i < m; i++) mpp[t[i]]++;

        while (r < n) {
            if (mpp.find(s[r]) != mpp.end()) {
                mpp[s[r]]--;
                if (mpp[s[r]] >= 0) count++;
            }
            while (count == m) {
                if (r - l + 1 < minlen) { minlen = r - l + 1; sInd = l; }
                if (mpp.find(s[l]) != mpp.end()) {
                    mpp[s[l]]++;
                    if (mpp[s[l]] > 0) count--;
                }
                l++;
            }
            r++;
        }
        return sInd == -1 ? "" : s.substr(sInd, minlen);
    }
};
