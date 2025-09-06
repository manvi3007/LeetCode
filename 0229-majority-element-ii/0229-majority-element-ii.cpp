class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int el1;
        int el2;
        int cnt1 = 0;
        int cnt2 = 0;
        vector<int > ls;
        int mini = (int) (nums.size()/3)+1;


        for (int i = 0; i<n; i++){
            if (nums[i] != el2 && cnt1 == 0){
                cnt1++;
                el1 = nums[i];
            }
            else if (nums[i] != el1 && cnt2 == 0){
                cnt2++;
                el2 = nums[i];
            }
            else if (nums[i]==el1){
                cnt1++;
            }
            else if (nums[i] == el2){
                cnt2++;
            }
            else{
                cnt1--;
                cnt2--;
            }
        }
        cnt1 = 0;
        cnt2 = 0;
        for (int i = 0; i<n; i++){
            if (el1 == nums[i]){
                cnt1++;
            }
            if (el2 == nums[i]){
                cnt2++;
            }


        }
        if (cnt1 >= mini){
            ls.push_back(el1);
        }
        if (cnt2 >= mini){
            ls.push_back(el2);
        }
        return ls;
    }
};