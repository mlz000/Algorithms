class Solution {
public:
    string shortestCompletingWord(string a, vector<string>& words) {
        unordered_map<char, int> cnt;
        for (auto c : a) {
            if (tolower(c) >= 'a' && tolower(c) <= 'z')  cnt[tolower(c)]++;
        }
        string ans = "";
        for (auto s : words) {
            unordered_map<char, int> cnt2;
            for (auto c : s)    cnt2[c]++;
            bool ok = 1;
            for (char c = 'a'; c <= 'z'; ++c)
                if (cnt[c] && cnt2[c] < cnt[c]) {
                    ok = 0;
                    break;
                }
            if (ok) {
                if (!ans.size())    ans = s;
                else if (s.size() < ans.size()) ans = s;
            }
        }
        return ans;
    }
};