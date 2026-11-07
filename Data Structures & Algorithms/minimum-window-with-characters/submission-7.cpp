class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> validWindow;
        unordered_map<char, int> window;
        for (char c : t) validWindow[c]++;

        pair<int, int> res = {-1, -1};
        int resLen = INT_MAX;
        int have = 0;
        int need = validWindow.size();
        int l = 0;
        for (int r = 0; r < s.size(); r++) {
            if (validWindow.contains(s[r])) {
                window[s[r]]++;
                if (window[s[r]] == validWindow[s[r]]) have++;
            }
            while (have == need) {
                int windowLength = r - l + 1;
                if (windowLength < resLen) {
                    res = {l, r};
                    resLen = windowLength;
                }
            
                if (window.contains(s[l])) {
                    window[s[l]]--;
                    if (window[s[l]] < validWindow[s[l]]) have--;
                }
                l++;
            }
        }
        return resLen == INT_MAX ? "" : s.substr(res.first, resLen);
    }
};
