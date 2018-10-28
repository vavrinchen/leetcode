
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> combinations;
        if(n == 0) {
            combinations.push_back("");
        } 
        else {
            for(int c = 0; c < n; c++) {
                for(auto left:generateParenthesis(c))
                    for(auto right:generateParenthesis(n-1-c)) 
                        combinations.push_back("(" + left + ")" + right);                     
                   
            }       
        }
        return combinations;
    }
   
};
