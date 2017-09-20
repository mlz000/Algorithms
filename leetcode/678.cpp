/*
Given a string containing only three types of characters: '(', ')' and '*', write a function to check whether this string is valid. We define the validity of a string by these rules:

Any left parenthesis '(' must have a corresponding right parenthesis ')'.
Any right parenthesis ')' must have a corresponding left parenthesis '('.
Left parenthesis '(' must go before the corresponding right parenthesis ')'.
'*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string.
An empty string is also valid.
Example 1:
Input: "()"
Output: True
Example 2:
Input: "(*)"
Output: True
Example 3:
Input: "(*))"
Output: True
*/
class Solution {
public:
    bool checkValidString(string s) {
        int n = s.size(), cnt = 0, mx = 0, mn = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '(')    ++mx, ++mn;
            else if (s[i] == ')')   --mx, mn = max(mn - 1, 0);
            else {
                ++mx;
                mn = max(mn - 1, 0);
            }
            if (mx < 0) return 0;
        }
        return mn == 0;
    }
};