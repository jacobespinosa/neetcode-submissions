class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> seen(nums.begin(), nums.end());

        int longest = 0;
        for (int num : seen) {
            int streak = 0;
            if (seen.find(num - 1) == seen.end()) { // start of sequence
                streak = 1;
                int current = num;
                while (seen.find(current + 1) != seen.end()) {
                    streak++;
                    current++;
                }
                longest = max(longest, streak);
            }
        }
        return longest;
    }
};
