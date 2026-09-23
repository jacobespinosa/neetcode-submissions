class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        unordered_map<char, int> sFreq;
        unordered_map<char, int> tFreq;

        for (int i = 0; i < s.size(); i++) {
            sFreq[s[i]]++;
            tFreq[t[i]]++;
        }
        return sFreq == tFreq;
    }
};
