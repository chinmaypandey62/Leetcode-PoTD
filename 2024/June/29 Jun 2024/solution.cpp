#pragma GCC optimize("Ofast")
static auto _ = [] () {ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return 0;}();

class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> parentOf(n), res(n);

        for (auto& it : edges)
            parentOf[it[1]].push_back(it[0]);

        vector<vector<bool>> visited(n, vector<bool>(n));

        for (int i = 0; i < n; ++i)
            addAll(parentOf, visited, i, res);

        for (auto& it : res)
            sort(it.begin(), it.end());

        return res;
    }

private:
    void addAll(vector<vector<int>>& parentOf, vector<vector<bool>>& visited,
                int node, vector<vector<int>>& res) {

        for (int i = 0; i < parentOf[node].size(); ++i) {
            int ancestor = parentOf[node][i];

            if (!visited[node][ancestor]) {
                res[node].push_back(ancestor);

                visited[node][ancestor] = true;
                addAll(parentOf, visited, ancestor, res);
            }

            for (int anc : res[ancestor]) {
                if (!visited[node][anc]) {
                    res[node].push_back(anc);
                    visited[node][anc] = true;
                }
            }
        }
    }
};