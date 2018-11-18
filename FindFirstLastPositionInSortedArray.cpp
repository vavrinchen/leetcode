class Solution {
public:
    int extremeInsertionIndex(vector<int>& nums, int target, bool left) {
        int lo = 0;
        int hi = nums.size();
        while(lo < hi) {
            int mid = (lo + hi) / 2;
            if(nums[mid] > target || (left && nums[mid] == target)) {
                hi = mid;
            } 
            else {
                lo = mid + 1;    
            }
        }
        return lo;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> targetRange = {-1, -1};
        int leftIdx = extremeInsertionIndex(nums, target, true);
        if(leftIdx == nums.size() || nums[leftIdx] != target) {
            return targetRange;
        }

        targetRange[0] = leftIdx;
        targetRange[1] = extremeInsertionIndex(nums, target, false) - 1;
        return targetRange;
    }
};
