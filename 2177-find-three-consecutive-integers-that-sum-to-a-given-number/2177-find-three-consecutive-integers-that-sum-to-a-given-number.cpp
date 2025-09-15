class Solution {
public:
    vector<long long> sumOfThree(long long num){
        if (num % 3 != 0) return {};
        int x = num/3 -1;
        return {x,x+1,x+2};

    }
};