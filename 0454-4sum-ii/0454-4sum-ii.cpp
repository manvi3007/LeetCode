class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int n = nums1.size() ;
        unordered_map<int,int>mpp;

        for (int a = 0; a < n; a ++){
            for (int b = 0; b < n;b++){
                mpp[nums1[a] + nums2[b]]++;
            }
        }
        
        int count = 0;
        for (int c = 0; c <n ; c++){
            for (int d = 0; d <n ; d++ ){
                int target = -(nums3[c]+nums4[d]);
                if (mpp.find(target) != mpp.end()){
                    count += mpp[target];
                }


            }
        }
        return count;
    }
};