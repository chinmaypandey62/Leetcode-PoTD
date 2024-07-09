#pragma GCC optimize("Ofast")
static auto _ = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double wait = 0;
        int currTime = 0;
        for (int i = 0; i < customers.size(); ++i) {
            if (customers[i][0] <= currTime) {
                wait += (currTime - customers[i][0]) + customers[i][1];
                currTime += customers[i][1];
            } else {
                wait += customers[i][1];
                currTime = customers[i][0] + customers[i][1];
            }
        }
        return (wait / customers.size());
    }
};