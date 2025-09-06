class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int>ans;
        long long  anss = 1;
        for (int i = 0 ; i <= rowIndex; i++){
            ans.push_back((int )anss);

            anss *= rowIndex-i;
            anss /= i+1;
        
        }
        
        return ans;
    }
};