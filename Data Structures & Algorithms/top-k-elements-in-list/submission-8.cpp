class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq; // value, freq
        for (int n : nums) freq[n]++;

        vector<vector<int>> bucket(nums.size() + 1); // index is freq, element is value
        for (const auto& [value, freq] : freq) {
            bucket[freq].push_back(value);
        }

        vector<int> res;
        for (int i = nums.size(); i >= 0; i--) {
            for (int n : bucket[i]) {
                res.push_back(n);
                if (res.size() == k) {
                    return res;
                }
            }
        }
        return res;
    }
};
