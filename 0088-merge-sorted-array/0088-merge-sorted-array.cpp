class Solution {
public:
    void swapp(vector<int>& nums1, int in1, vector<int>& nums2, int in2){
        if (nums1[in1]>nums2[in2]){
            swap (nums1[in1],nums2[in2]);
        }
    }
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int len = n+m;
        int gap = (len/2) + (len%2);
        while(gap>0){
            int left = 0;
            int right = left +gap;
            while(right<len){

            
            if (left<m && right >= m ){
                swapp(nums1,left,nums2,right-m);
            }
            else if (left >= m){
                swapp(nums2,left-m,nums2,right-m);
            }
            else {
                swapp(nums1,left,nums1,right);
            }
            left++;
            right ++;
            }
            if (gap ==1) {break;}
            gap = (gap/2) + (gap %2);
            }
            for (int i = 0;i<n;i++){
                nums1[m+i]=nums2[i];
            }
        }
    
};