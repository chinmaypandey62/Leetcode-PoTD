class Solution {
public:
    int numWaterBottles(int empty, int ex) {
        int res = empty;

        while(empty >= ex) {
            res += (empty / ex);
            empty = (empty / ex) + (empty % ex);
        }

        return res;
    }
};