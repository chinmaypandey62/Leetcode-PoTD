class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> freq1;
        for(int& i : nums1) ++freq1[i];

        vector<int> res;
        for(int& i : nums2)
            if(freq1[i]) res.push_back(i), --freq1[i];

        return res;
    }
};