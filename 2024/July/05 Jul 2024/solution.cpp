class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> res(2, INT_MAX);
        int prev = head->val, prevC = -1000001, fst = 0, i = 0;
        
        head = head->next;
        if(!head->next) return {-1, -1};
        while(head->next) {
            ++i;
            int v = head->val, n = head->next->val;

            if((v > n && v > prev) || (v < n && v < prev)) {
                if(!fst) fst = i;

                res[0] = min(res[0], (i - prevC));
                prevC = i;
            }
            prev = v;
            head = head->next;
        }

        if(prevC == fst || !fst) return {-1, -1};
        res[1] = prevC - fst;

        return res;
    }
};