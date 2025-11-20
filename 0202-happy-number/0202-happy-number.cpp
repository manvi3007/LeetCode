class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int>st;

        while(true){
            int sum = 0;
            int temp = n;
            while(temp!= 0){
                sum += pow(temp%10,2.0);
                temp = temp/10;}

                if (sum == 1){
                    return true;
                }
                if(st.find(sum) != st.end()){
                    return false;
                }
                st.insert(sum);

                n = sum;

                


            
        }
        return false;
    }
};