class Solution {
public:
    bool isPerfectSquare(int num) {
        int low = 1;
        int high = num;
        while(low <= high){
            long long mid = low + (high - low)/2;
            long long a = mid * mid;
            if( a== num){
                return true;
            }
            else if (a > num){
                high = mid -1;
            }
            else{
                low = mid +1;
            }
        }
        return false;
    }
};