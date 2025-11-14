class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(),nums.end());
        int high = accumulate(nums.begin(),nums.end(),0);
        int res = high;

        while(low <= high){
            int mid = low + (high - low)/2;

            if (ans(nums,k,mid)){
                res = mid;
                high = mid - 1;

            }
            else{
                low = mid +1;
            }
        }
        return res;
    }

    bool ans(vector<int>num,int k, int lar){
        int sub = 1;
        int sum = 0;
        for (int i = 0; i < num.size();i++){
            sum += num[i];

            if(sum > lar){
                sub++;
                if(sub > k){
                    return 0;
                }
                sum = num[i];
            }
        }
        return true;

    }
};