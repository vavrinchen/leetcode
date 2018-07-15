class Solution {
public:
    string convert(string s, int numRows) {
        int curRow = 0;
        bool goingDown = false;
        if(numRows==1) {
            return s;
        }
        string row[numRows];
        for(char c:s) {
            row[curRow] += c;
            if(curRow==0 || curRow== numRows -1) {
                goingDown = !goingDown;
            }
            curRow += goingDown?1:-1;
        }
        
        string result;
        for(string rows:row) {
            result += rows;
        }
        return result;
        
    }
};
