
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> combinations;
        backtrack(combinations, "", 0, 0, n);
        return combinations;
    }
    
    void backtrack(vector<string> &combinations, string current, int open, int close, int sizeRes)
    {

        if(2*sizeRes == current.length())
        {
                   
           combinations.push_back(current);   
           return;
            
        }

        if (open < sizeRes) {

            backtrack(combinations, current+"(", open+1, close, sizeRes);
        }
        if (close < open) {
            backtrack(combinations, current+")", open, close+1, sizeRes);
        }

    }
   
};
