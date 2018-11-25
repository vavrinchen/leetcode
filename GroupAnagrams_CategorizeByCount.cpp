
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res; 
        
        unordered_map<string, vector<string>> tmp;
        for(auto s : strs) {
            vector<int> count(26, 0);
            string t = "";
            for(char c : s) {
                count[c - 'a'] ++;
            }
            for(int e : count) {
                t += "#" + to_string(e); 
            }
            tmp[t].push_back(s);
        }    
        for (auto a : tmp) {
            res.push_back(a.second);
        }
        return res;
    }
};
