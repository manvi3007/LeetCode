class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cnt1 = 0;
        int cnt2 = 0;
        int n = nums.size();
        int el1 = INT_MIN;
        int el2 = INT_MIN;
        for (int i =0; i<n;i++){
            if (cnt1 == 0 && el2 != nums[i]){
                cnt1 = 1;
                el1 = nums[i];
            }
            else if (cnt2 == 0 && el1 != nums[i]){
                cnt2 = 1;
                el2 = nums[i];
            }
            else if (el1 == nums[i]){
                cnt1++;
            }
            else if (el2  == nums[i]){
                cnt2++;
            }
            else {
                cnt1 --;
                cnt2 -- ;
            }
        }
        vector<int>ls;
        int cnt11 = 0; int cnt22 = 0;
        for (int i = 0;i<n;i++){
            if(el1 == nums[i]){
                cnt11++;
            }
            else if (el2 == nums[i]){
                cnt22++;
            }

        }
        int mini = (int) n/3 +1;
        if (cnt11 >= mini){
            ls.push_back(el1);
        }
        if (cnt22 >= mini){
            ls.push_back(el2);

        }
        sort(ls.begin(),ls.end());
        return ls;
    }
};