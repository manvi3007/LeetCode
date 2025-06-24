class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums2.size();
        vector<int>nge(n,-1);
        stack<int>st;
        for (int i = n-1;i>=0;i--){
            while(!st.empty() && st.top() <= nums2[i] ){
                st.pop();
            }
            
            if (!st.empty()){
                nge[i] = st.top();
               
            }
             st.push(nums2[i]);
        }

        int pos[10001];
        for (int i = 0;i<nums2.size();i++){
            pos[nums2[i]] = i;
        }



        vector<int> res;
        for(int x :nums1){
            int i = pos[x];
            res.push_back(nge[i]);

        }
        return res;

    }
};