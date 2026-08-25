class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
        unordered_map<string, vector<string>> map;

        for (const auto& s : strs)
        {
            string sortedS = s;
            sort(sortedS.begin(), sortedS.end());
            map[sortedS].push_back(s);
        }

        vector<vector<string>> res;
        for (const auto& p : map)
        {
            res.push_back(p.second);
        }
        return res;
    }
};
