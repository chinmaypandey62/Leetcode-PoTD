class Solution {
public:
    int minDifference(vector<int>& nums) {
        if(nums.size() < 5) return 0;
        int res = INT_MAX;
        sort(nums.begin(), nums.end());

        for(int i = 3, j = nums.size() - 1; i >= 0; --i, --j) {
            int t = nums[j] - nums[i];
            res = min(res, t);
        }

        return res;
    }
};