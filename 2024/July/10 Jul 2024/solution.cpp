class Solution {
public:
    int minOperations(vector<string>& logs) {
        int count = 0;

        for(string& s : logs) {
            if(s == "../") {
                if(count) --count;
            }
            else if(s != "./")  ++count;
        }

        return count;
    }
};