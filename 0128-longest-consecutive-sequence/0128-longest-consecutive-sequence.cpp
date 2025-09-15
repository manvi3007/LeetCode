class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>st (nums.begin(),nums.end());
        
        int len = 0;
        int lonn= 0;

        for (int i : st ){
            if (st.find(i-1) == st.end()){
                len = 1;
                while (st.find(len + i) != st.end()){
                    len++;
                }
                lonn = max(lonn, len);
            }
            
        
            


        }
        return lonn;
    }
};