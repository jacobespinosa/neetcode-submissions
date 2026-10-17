class Solution {
public:
    string minWindow(string s, string t) {
        if (t.empty()) return "";

        unordered_map<char, int> countT, window;
        for (char c : t) countT[c]++;

        int have = 0;
        int need = countT.size();

        pair<int, int> res = {-1, -1};
        int resLen = INT_MAX;
        int l = 0;
        int r = 0;

        while (r < s.size()) {
            window[s[r]]++;
            if (countT.contains(s[r]) && window[s[r]] == countT[s[r]]) have++;

            while (have == need) {
                int windowLen = r - l + 1;
                if (windowLen < resLen) {
                    resLen = r - l + 1;
                    res = {l, r};
                }

                window[s[l]]--;
                if (countT.contains(s[l]) && window[s[l]] < countT[s[l]]) have--;
                l++;
            }
            r++;
        }
        return resLen == INT_MAX ? "" : s.substr(res.first, resLen);
    }
};
