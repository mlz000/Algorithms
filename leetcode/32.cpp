class Solution {
public:
	stack<int> st;
    int longestValidParentheses(string s) {
        int l = s.size();
		int mx = 0;
		st.push(-1);
		for (int i = 0; i < l; ++i) {
			int p = st.top();
			if (~p && s[p] == '(' && s[i] == ')') {
				st.pop();
				mx = max(mx, i - st.top());
			}
			else st.push(i);
		}
		return mx;
    }
};