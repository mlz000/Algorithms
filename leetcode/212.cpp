struct Trie {
	vector<Trie*> son;
	Trie() : son(vector<Trie*>(26, NULL)){}
};
class Solution {
public:
	int n, m;
	vector<string> ans;
	unordered_map<string, bool> mp;
	Trie* rt;
	bool check(int x, int y) {
		return x >= 0 && x < n && y >= 0 && y < m;
	}
	void insert(string s) {
		Trie *now = rt;
		for (auto c : s) {
			if (!now -> son[c - 'a'])	now -> son[c - 'a'] = new Trie();
			now = now -> son[c - 'a'];
		}
	}
	void find(vector<vector<char>>& a, int x, int y, Trie* now, string s) {
	    if (!check(x, y) || a[x][y] == '$')   return;
		char c = a[x][y];
		Trie *t = now -> son[c - 'a'];
		if (!t)	return;
		if (mp[s + c])	ans.push_back(s + c);
		a[x][y] = '$';
		find(a, x, y + 1, t, s + c);
		find(a, x, y - 1, t, s + c);
		find(a, x + 1, y, t, s + c);
		find(a, x - 1, y, t, s + c);
		a[x][y] = c;
	}
    vector<string> findWords(vector<vector<char>>& a, vector<string>& b) {
        n = a.size(), m = a[0].size();
		rt = new Trie();
    	for (auto s : b)	mp[s] = 1;
		for (auto it : mp)	insert(it.first);
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j) 
				find(a, i, j, rt, "");
		sort(ans.begin(), ans.end());
		ans.erase(unique(ans.begin(), ans.end()), ans.end());
		return ans;
	}
};