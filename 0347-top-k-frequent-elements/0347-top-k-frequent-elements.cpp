class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> mp;
        for (int i = 0; i < n; i++){
            mp[nums[i]]++;
        }
        vector<pair<int,int>>ans;
        for (const auto& p : mp){
            ans.push_back({p.second,p.first});
        }
        sort(ans.rbegin(),ans.rend());
        vector<int>res;
        for (int i = 0; i < k ; i++){
            res.push_back(ans[i].second);


        }
        return res;
    }
};