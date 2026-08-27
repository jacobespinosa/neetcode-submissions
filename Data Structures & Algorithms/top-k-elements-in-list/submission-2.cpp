class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for (int n : nums) mp[n]++;

        vector<vector<int>> freq(nums.size() + 1);
        for (auto& [num, count] : mp) {
            freq[count].push_back(num);
        }

        vector<int> result;
        for (int i = nums.size(); i >= 0; i--) {
            for (int n : freq[i]) {
                result.push_back(n);
                if (result.size() == k) return result;

            }
        }
        return result;
    }
};
