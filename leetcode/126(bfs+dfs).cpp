#define pb push_back
#define mp make_pair
#define F first
#define S second
typedef pair<string, int> psi;
class Solution {
	public:
	vector<vector<string> > s;
	map<string, set<psi> > fa;
	queue<psi> q;
	void dfs(string u, string st, vector<string> now) {
		now.pb(u);
		if (u == st) {
			reverse(now.begin(), now.end());
			s.pb(now);
			return ;
		}
		for (auto v : fa[u])
			dfs(v.F, st, now);
	}
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& P) {
		set<string> wordList;
		for (auto ss : P)	wordList.insert(ss);
		if (wordList.find(endWord) == wordList.end())	return s;
		wordList.insert(endWord);
		q.push(mp(beginWord, 1));
		while (q.size()) {
			psi t = q.front();
			q.pop();
			for (int i = 0; i < t.F.size(); ++i)
				for (int j = 0; j < 26; ++j) {
					string ss = t.F;
					ss[i] = 'a' + j;
					if (wordList.count(ss)) {
						q.push(mp(ss, t.S + 1));
						wordList.erase(ss);
						fa[ss].insert(t);
					}
					else if (fa.count(ss) && fa[ss].begin() -> second == t.S)	fa[ss].insert(t);
				}
		}
		vector<string> now;
		dfs(endWord, beginWord, now);
		return s;
    }
};
