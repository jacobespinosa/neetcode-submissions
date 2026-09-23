class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> seen;
        int left = 0;
        int right = 0;
        int longest = 0;

        while (right < s.size()) {
            while (seen.contains(s[right])) {
                seen.erase(s[left]);
                left++;
            }
            longest = max(longest, right - left + 1);
            seen.insert(s[right]);
            right++;
        }
        return longest;
    }
};
