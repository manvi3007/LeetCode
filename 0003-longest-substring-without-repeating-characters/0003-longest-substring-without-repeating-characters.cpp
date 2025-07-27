class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       int hash[256];
       fill(hash, hash + 256, -1);
       int len = 0;
       int maxlen = 0;
       int l =0;
       int r = 0;
       int n = s.size();
       while(r<n){
        if (hash[s[r]] != -1){
            if (hash[s[r]] >= l){
                l = hash[s[r]] +1;
            }
            
        }
        len = r-l+1;
        maxlen = max(maxlen, len);
        hash[s[r]] = r;
        r++;
       }
       return maxlen;



    }
};