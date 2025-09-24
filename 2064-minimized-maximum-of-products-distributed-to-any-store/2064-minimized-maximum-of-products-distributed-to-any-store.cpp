class Solution {
public:
    bool check(int n ,vector<int>& q, int x){
        int m = q.size();
        int stores = 0;
        for (int i = 0; i < m ; i++){
            stores += ceil((double)q[i]/(double)x);
        }
        return stores <= n;
    }
    int minimizedMaximum(int n, vector<int>& quantities) {
        int low = 1;
        int high = *max_element(quantities.begin(),quantities.end());
        int ans = 0;
        while(low<=high){
            int mid = low + (high - low)/2;
            if(check(n,quantities,mid)){
                ans = mid;
                high = mid -1;
            }
            else{
                low = mid +1;
            }

        }
        return ans;
    }
};