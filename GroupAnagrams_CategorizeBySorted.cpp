
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res; 
        unordered_map<string, vector<string>> tmp;
        for(auto s : strs) {
            auto key = s;
            sort(key.begin(), key.end());
            tmp[key].push_back(s);
        }    
        for (auto a : tmp) {
            res.push_back(a.second);
        }
        return res;
    }
};
