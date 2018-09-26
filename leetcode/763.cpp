class Solution {
public:
    int tot[26], cnt[26];
    bool ok[501][501];
    vector<int> partitionLabels(string S) {
        int n = S.size();
        for (auto c : S)    ++tot[c - 'a'];
        vector<int> ans;
        int l = 0;
        for (int r = 0; r < n; ++r) {
            ++cnt[S[r] - 'a'];
            bool ok = 1;
            for (int i = 0; i < 26; ++i) {
                if (cnt[i] && cnt[i] != tot[i]) {
                    ok = 0;
                    break;
                }
            }
            if (ok) {
                ans.push_back(r - l + 1);
                memset(cnt, 0, sizeof(cnt));
                l = r + 1;
            }
        }
        return ans;
    }
};