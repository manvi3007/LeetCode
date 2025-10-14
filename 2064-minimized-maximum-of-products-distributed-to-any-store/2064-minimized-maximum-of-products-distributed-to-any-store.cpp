class Solution {
public:
    bool check(vector<int>& q, int n,int p ){
        int m = q.size();
        int sum = 0;
        for (int i = 0; i < m; i++){
            sum += ceil((double)q[i]/(double)n);
        }
        return sum <= p;
    }
    int minimizedMaximum(int n, vector<int>& quantities) {
        int low = 0;
        int high = *max_element(quantities.begin(),quantities.end());
        int res = quantities.size();
        while (low <= high){
            int mid = low + (high - low)/2;
            if(check(quantities,mid,n)){
                res = mid;
                high = mid -1;
            }
            else{
                low = mid +1;
            }
        }
        return res;
    }
};