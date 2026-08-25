class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;

        unordered_map<char, int> Sfreq;
        unordered_map<char, int> Tfreq;
        for (int i = 0; i < s.size(); i++) {
            Sfreq[s[i]]++;
            Tfreq[t[i]]++;
        }
        return Sfreq == Tfreq;
    }
};
