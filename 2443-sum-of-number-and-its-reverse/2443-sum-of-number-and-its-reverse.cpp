class Solution {
public:
    bool sumOfNumberAndReverse(int num) {
        
        for (int i = 0 ; i <= num ; i++){
            int rev = 0;
            int y = i;

            while ( y > 0){
                rev = rev * 10 + y % 10 ;
                y /= 10;
            }
            if (i + rev == num){
                return true;
            }



        }
        return false;
    }
};