class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());

        for (int i = 0; i< n ; i++){
            if (i > 0 && nums[i]==nums[i-1]) continue;

            for (int j = i+1; j < n; j ++ ){
                if (j != i+1 && nums[j] == nums[j-1]) continue;

                int l = j+1;
                int k = n-1;

                while (l <k){
                    long long sum = 1LL * nums[i]+nums[j]+nums[k]+nums[l];

                    if (sum < target ){
                        l++;
                    }
                    else if (sum > target ){
                        k--;
                    }
                    else {
                        vector<int>temp = {nums[i],nums[j],nums[k],nums[l]};
                        ans.push_back(temp);
                        l++;
                        k--;
                        while(l<k && nums[l] == nums[l-1]) l++;
                        while(l < k && nums[k] == nums[k+1]) k--; 
                    }

                }
            }
        }
        return ans;
    }
};