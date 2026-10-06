class Solution {
public:
    bool isValid(string s) {
        stack<char> stack;
        unordered_map<char, char> map;
        map[')'] = '(';
        map[']'] = '[';
        map['}'] = '{';

        for (char c : s) {
            if (map.contains(c)) {
                if (!stack.empty() && stack.top() == map[c]) {
                    stack.pop();
                } 
                else {
                    return false;
                }
            }
            else {
                stack.push(c);
            }
        }
        return stack.empty();
    }
};
