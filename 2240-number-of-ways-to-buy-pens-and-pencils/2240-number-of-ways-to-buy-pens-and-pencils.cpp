class Solution {
public:
    long long waysToBuyPensPencils(int total, int cost1, int cost2) {
        long long ways = 0;
        for (long long pens = 0; pens * (long long)cost1 <= total; pens++) {
            long long remaining = total - pens * (long long)cost1;
            ways += remaining / cost2 + 1;
        }
        return ways;
    }
};
