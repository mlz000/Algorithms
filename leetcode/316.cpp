class Solution {
public:
    int cnt[26];
    bool v[26];
    string removeDuplicateLetters(string s) {
        for (auto c : s)    ++cnt[c - 'a'];
        string ans = "";
        for (auto c : s){
            int x = c - 'a';
            --cnt[x];
            if (v[x])   continue;
            while (c < ans.back() && cnt[ans.back() - 'a'] > 0) {
                v[ans.back() - 'a'] = 0;
                ans.pop_back();
            }
            ans.push_back(c);
            v[x] = 1;
        }
        return ans;
    }
};