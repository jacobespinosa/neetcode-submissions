class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for (int n : nums) freq[n]++;

        vector<vector<int>> bucket(nums.size() + 1);
        for (const auto& [num, freq] : freq) {
            bucket[freq].push_back(num);
        }

        vector<int> result;
        for (int i = nums.size(); i >= 0; i--) {
            if (!bucket[i].empty()) {
                for (int n : bucket[i]) {
                    result.push_back(n);
                    if (result.size() == k) {
                        return result;
                    }
                }
            }
        }
        return result;
    }
};
