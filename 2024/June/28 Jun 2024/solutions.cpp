class Solution1 {
public:
    int findCenter(vector<vector<int>>& edges) {
        vector<int>freq(edges.size() + 2, 0);

        for(int i = 0; i < edges.size(); ++i) {
            ++freq[edges[i][0]];
            ++freq[edges[i][1]];
        }

        for(int i = 0; i < freq.size(); ++i) 
            if(freq[i] == edges.size()) return i;

        return 0;
    }
};

class Solution2 {
public:
    int findCenter(vector<vector<int>>& edges) {
        if(edges[0][0] == edges[1][0] || edges[0][0] == edges[1][1]) return edges[0][0];

        return edges[0][1];
    }
};