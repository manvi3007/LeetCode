class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        vector<int> ans;
        int i = 0;
        int j = 0;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());



        while(i < n1 && j < n2){
            if(nums1[i]>nums2[j]){
                j++;
            }
            else if (nums2[j]>nums1[i]){
                i++;
            }
            else{
                if(nums1[i]==nums2[j]){
                    if(ans.size() == 0 || ans.back() != nums1[i]){
                        ans.push_back(nums1[i]);
                        i++;
                        j++;
                    }
                    else{
                        i++;
                        j++;
                    }
                }
            }
        }
        return ans;
    }
};