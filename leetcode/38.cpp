class Solution {
public:
    string countAndSay(int n) {
        string ans = "1";
        for (int i = 1; i < n; ++i) {
            string now = "";
            for (int j = 0; j < ans.size(); ++j) {
                int cnt = 1;
                while (j + 1 < ans.size() && ans[j + 1] == ans[j]) {
                    ++j, ++cnt;
                }
                now += to_string(cnt) + ans[j];
            }
            ans = now;
        }
        return ans;
    }
};