class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target);
};



std::vector<int> Solution::twoSum(std::vector<int> &nums, int target) {
	std::unordered_map<int, int> myMap = {};
	std::vector<int> result(0);
		for (int i = 0; i < nums.size(); i++) {
			myMap.insert({nums[i], i});
		}
		for (int i = 0; i < nums.size(); i++) {
			auto v = myMap.find(target - nums[i]);

			if (v != myMap.end() && myMap[target - nums[i]] != i) {
				result.push_back(i);
				result.push_back(v->second);
				return result;
			}
		}
		return {};
}

