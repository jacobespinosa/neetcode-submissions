class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> closeToOpen = {
            {']', '['},
            {')', '('},
            {'}', '{'}
        };
        stack<char> theStack;

        for (int i = 0; i < s.size(); i++) {
            if (closeToOpen.contains(s[i])) {
                if (theStack.empty()) {
                    return false;
                }
                else {
                    if (theStack.top() != closeToOpen[s[i]]) {
                        return false;
                    }
                    else {
                        theStack.pop();
                    }
                }
            } else {
                theStack.push(s[i]);
            }
        }
        return theStack.empty();
    }
};
