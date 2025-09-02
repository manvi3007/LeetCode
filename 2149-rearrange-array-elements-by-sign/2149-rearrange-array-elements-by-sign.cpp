class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size(); 
        int pos = 0;
        int neg = 1;
        vector<int>arr1(n,0);
        for (int i = 0; i<n; i++){
            if (nums[i] < 0){
                arr1[neg] = nums[i];
                neg += 2;
            }
            else{
                arr1[pos] = nums[i];
                pos += 2;
            }

        }
        return arr1;
    }
};