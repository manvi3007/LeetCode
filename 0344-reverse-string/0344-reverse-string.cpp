class Solution {
public:
    void reverseString(vector<char>& s) {
        int n = s.size();
        int m = 0;
        int e = n-1;
        while (m<e){
            swap(s[m++],s[e--]);
        }
    }
};