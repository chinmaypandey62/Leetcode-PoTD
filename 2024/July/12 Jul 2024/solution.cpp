class Solution {
public:
    int maximumGain(string s, int x, int y) {
        string stack;
        int res = 0;
        char c1 = 'b', c2 = 'a';

        if (x > y) {
            c1 = 'a';
            c2 = 'b';
            swap(x, y);
        }

        for (int i = 0; i < s.size(); ++i) {
            if (!stack.empty() && stack.back() == c1 && s[i] == c2) {
                res += y;
                stack.pop_back();
            } else {
                stack += s[i];
            }
        }

        string stk;
        for (int i = 0; i < stack.size(); ++i) {
            if (!stk.empty() && stk.back() == c2 && stack[i] == c1) {
                res += x;
                stk.pop_back();
            } else {
                stk += stack[i];
            }
        }

        return res;
    }
};