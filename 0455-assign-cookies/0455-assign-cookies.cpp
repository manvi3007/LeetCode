class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int m = g.size();
        int n = s.size();
        int r = 0;
        int l = 0;
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());

        while (l<n && r < m){
            if (s[l] >= g[r]){
                r++;
            }
            l++;
        }
        return r;

    }
};