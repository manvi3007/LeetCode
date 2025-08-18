class Solution {
public:
    int jump(vector<int>& nums) {
        int l = 0;
        int r =0;
        int farthest = 0;
        int jump = 0;
        int n = nums.size();
        while ( r<n-1){
          for (int ind = l ; ind <= r; ind ++){
            farthest = max(farthest, ind+nums[ind]);
          }
          l = r+1;
          jump++;
          r = farthest;
        }
        return jump;
    }
};