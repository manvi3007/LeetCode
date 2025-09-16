class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int l = 0 ;
        int r = n-1;
        int maxA = INT_MIN;
        while ( l < r){
            int res =  (r-l)* min(height[l],height[r]);
            maxA = max(res,maxA);
            if (height[l]>height[r]){
                r--;
            }
            else{
                l++;
            }
            
        }
        return maxA;

    }
};