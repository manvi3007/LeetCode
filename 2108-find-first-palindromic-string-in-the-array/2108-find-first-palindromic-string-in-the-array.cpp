class Solution {
public:
    bool check(string s){
        int l = 0;
        int r = s.size()-1;

        while(l < r){
            if (s[l]!=s[r]){
                return false;
            }
            l++;
            r--;

        }
        return true;
    }
    string firstPalindrome(vector<string>& words) {
        int n = words.size();
        for (string &w : words){
            if(check(w)){
                return w;
            }
        }
        return "" ;

        }
        
    
};