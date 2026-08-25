class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        unordered_set<char> charSet;
        int res = 0;
        int l = 0;

        for (int r = 0; r < s.length(); r++)
        {
            while(charSet.find(s[r]) != charSet.end())
            {
                charSet.erase(s[l]);
                l++;
            }
            charSet.insert(s[r]);
            res = max(r-l+1, res);
        }
        return res;
    }

};
