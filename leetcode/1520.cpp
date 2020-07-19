class Solution {
public:
    int find_pos(string s, int pos, vector<int> l, vector<int> r) {
        int max_right = r[s[pos] - 'a'];
        for (int i = pos + 1; i <= max_right; ++i) {
            if (l[s[i] - 'a'] < pos) return -1;
            max_right = max(max_right, r[s[i] - 'a']);
        }
        return max_right;
    }
    vector<string> maxNumOfSubstrings(string s) {
        vector<int> l(26, INT_MAX), r(26, INT_MIN);
        vector<pair<int, int>> first(26, make_pair(INT_MAX, 0));
        for (int i = 0; i < s.size(); ++i) {
            l[s[i] - 'a'] = min(l[s[i] - 'a'], i);
            r[s[i] - 'a'] = max(r[s[i] -'a'], i);
            first[s[i] - 'a'] = make_pair(l[s[i] - 'a'], s[i] - 'a');
        }
        sort(first.begin(), first.end());
        vector<string> ans(1);
        int last_right = INT_MAX;
        for (int i = 0; i < 26; ++i) {
            int pos = first[i].first;
            int c = first[i].second;
            if (pos != INT_MAX) {
                int max_right = find_pos(s, pos, l, r);
                if (~max_right) {
                    if (pos > last_right)  ans.push_back("");
                    last_right = max_right;
                    ans.back() = s.substr(pos, max_right - pos + 1);
                }
            }
        }
        return ans;
    }
};