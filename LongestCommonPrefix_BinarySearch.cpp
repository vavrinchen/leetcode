class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {        
        if(strs.size() == 0) {
            return "";
        }
        
        int minLen = INT_MAX;
        for (std::string str : strs)
            minLen = std::min<int>(minLen, str.length());
        int low = 1;
        int high = minLen;
        
        while(low<=high)
        {
            int middle = (low + high)/2;
            if(isCommonPrefix(strs, middle))
            {
                low = middle + 1;
            } 
            else
            {
                high = middle - 1;
            }
        }
        return strs[0].substr(0, (low + high)/2);
    }
    bool isCommonPrefix(vector<string>& strs, int middle)
    {
        string common = strs[0].substr(0, middle);
        for(int i = 0; i< strs.size(); i++)
        {
            if(strs[i].find(common) != 0) return false;
        }
        return true;
    }
};
