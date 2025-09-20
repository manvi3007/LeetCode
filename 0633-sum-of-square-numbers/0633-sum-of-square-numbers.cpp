class Solution {
public:
    bool check(int x){
        int low = 0;
        int high = x;
        while(low <= high){
            long long mid = low + (high - low)/2;
            if (mid * mid == x){
                return true;
            }
            else if (mid * mid > x){
                high = mid - 1;
            }
            else{
                low = mid +1;
            }
        }
        return false;
    }
    bool judgeSquareSum(int c) {
        for (long long b = 0; b*b <= c; b++){
            long long a = c - b*b;
            if (check (a)) return true;
        }
        return false;
    }
};