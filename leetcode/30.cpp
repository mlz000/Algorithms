class Solution {
public:
	vector<int> ans;
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string, int> cnt;
        for (string s : words)	++cnt[s];
        int n = s.size(), m = words.size(), len = words[0].size();
        for (int i = 0; i < n - m * len + 1; ++i) {
            unordered_map<string, int> now;
            int j = 0;
            for (; j < m; ++j) {
                string word = s.substr(i + j * len, len);
                if (cnt.find(word) != cnt.end()) {
                    ++now[word];
                    if (now[word] > cnt[word])	break;
                } 
                else break;
            }
            if (j == m) ans.push_back(i);
        }
        return ans;
    }
};
