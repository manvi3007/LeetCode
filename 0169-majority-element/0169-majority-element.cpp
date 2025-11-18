class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = 0;
        int cnt = 0;
        int res = 0;

        for (int num : nums){
            
            if(cnt == 0){
                res = num;
            }
            (num == res ) ? cnt ++ : cnt--;
        }
        return res;
    }
};
