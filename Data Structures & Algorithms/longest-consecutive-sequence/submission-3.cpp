class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> seen(nums.begin(), nums.end());
        int longest = 0;

        for (int n : seen) {
            if (!seen.contains(n - 1)) { // start of sequence
                int streak = 1;
                int i = 1;
                while (seen.contains(n + i)) {
                    streak++;
                    i++;
                }
                longest = max(longest, streak);
            }
        }
        return longest;
    }
};
