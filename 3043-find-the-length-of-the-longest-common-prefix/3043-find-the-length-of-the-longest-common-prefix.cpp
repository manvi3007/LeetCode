class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<string> s; 

        for (int x : arr1){
            string str = to_string(x);
            string prefix = "";

            for (char c : str){
                prefix += c;
                s.insert(prefix);
            }
        }
        int ans = 0;

        for (int y : arr2){
            string str = to_string(y);
            string prefix = "";

            for (char c : str ){
                prefix += c;
                if(s.count(prefix)){
                    ans = max (ans, (int)prefix.length());
                }
            }
        }
        return ans;
    }
};