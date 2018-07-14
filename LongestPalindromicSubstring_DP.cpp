class Solution {
public:
    string longestPalindrome(string s) {
        int start = 0;
        int maxLength = 1;
        int n = s.length();
        bool  table[n][n]={false};

        for (int i = 0; i < n; i++) {
            table[i][i] = true;
        }
        for(int i = 0; i < n-1; i++) {
            if(s[i] == s[i+1]) {
                table[i][i+1] = true;
                start = i;
                maxLength = 2;
            }    
        }
        for(int k=3; k<=n; k++) {
            for(int i=0; i < n-k+1; i++) {
                int j = i+k-1;
                if(table[i+1][j-1]==true && s[i]==s[j]){
                    table[i][j]=true;
                    start = i;
                    maxLength = k;
                }
            }
        }
        return s.substr(start, maxLength );
    }   
   
};
