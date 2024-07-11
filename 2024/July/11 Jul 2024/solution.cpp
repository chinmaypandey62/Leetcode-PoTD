class Solution {
public:
    string reverseParentheses(string s) {
        s += ')';
        int index = 0;
        string res = helper(s, index);
        reverse(res.begin(), res.end());
        return res;
    }

    string helper(string& s, int& i) {
        string temp;
        while (s[i] != ')') {
            if (s[i] == '(') {
                i++;
                string str = helper(s, i);
                temp += str;
            } else {
                temp += s[i++];
            }
        }
        i++;
        reverse(temp.begin(), temp.end());
        return temp;
    }
};