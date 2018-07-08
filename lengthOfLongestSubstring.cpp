class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> mymap;
        int ans = 0;
        for (int j = 0, i = 0; j < s.length(); j++) {
                auto search = mymap.find(s.at(j));
                if (search != mymap.end()) {
                    i = std::max(i, mymap[s.at(j)] + 1); 
                } 
                mymap[s.at(j)] = j;
                ans = std::max(ans, j - i + 1);               
        }
        return ans;
    }
};
