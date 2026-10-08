class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;

        unordered_map<char, int> SFreq;
        unordered_map<char, int> TFreq;
        for (int i = 0; i < t.size(); i++) {
            SFreq[s[i]]++;
            TFreq[t[i]]++;
        }
        return SFreq == TFreq;
    }
};
