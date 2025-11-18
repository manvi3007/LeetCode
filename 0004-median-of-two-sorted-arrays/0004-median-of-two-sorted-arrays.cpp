class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        int tot = n1 + n2;

        int half = (n1 + n2+1)/2;

        if (nums1.size()>nums2.size()){
            return findMedianSortedArrays(nums2, nums1); 
        }
        int l = 0;
        int r = nums1.size();

        while (l <= r){
            int i = l + (r-l)/2;
            int j = half - i;

            int Aright =  i < nums1.size() ? nums1[i] : INT_MAX;
            int Aleft =  i > 0 ? nums1[i-1] : INT_MIN;
            int Bright = j < nums2.size() ? nums2[j] :   INT_MAX;
            int Bleft = j > 0 ? nums2[j-1] : INT_MIN;

            if (Aright >= Bleft && Aleft <= Bright){
                if (tot % 2 != 0){
                    return max (Aleft,Bleft);
                }
                else{
                    return (min(Aright,Bright) + max (Aleft,Bleft))/2.0;
                }
            }
            else if (Aleft > Bright){
                r = i - 1 ;
            }
            else{
                l = i +1;
            }
        }
        return -1;


    }
};