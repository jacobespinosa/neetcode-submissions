class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> freq;
        int l = 0;
        int longest = 0;
        int mfc = 0;
        for (int r = 0; r < s.size(); r++) {
            freq[s[r]]++;
            mfc = max(mfc, freq[s[r]]);

            while ((r - l + 1) - mfc > k) {
                freq[s[l]]--;
                l++;
            }
            longest = max(longest, r - l + 1);
        }
        return longest;
    }
};
