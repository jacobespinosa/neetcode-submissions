class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;

        for (int i = 0; i < strs.size(); i++) {
            vector<int> count(26, 0);
            for (char c : strs[i]) {
                count[c - 'a']++;
            }
            string key = to_string(count[0]);
            for (int i = 1; i < count.size(); i++) {
                key += ',' + to_string(count[i]);
            }
            mp[key].push_back(strs[i]);
        }
        vector<vector<string>> result;
            for (const auto& pair : mp) {
                result.push_back(pair.second);
            }
            return result;
        return {};
    }
};
