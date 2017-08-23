#define mp make_pair
#define F first
#define S second
typedef pair<string, int> psi;
class Solution {
public:
    queue<psi> q;
    unordered_map<string, bool> G, vis;
    int ladderLength(string beginWord, string endWord, vector<string>& P) {
		for (auto ss : P)	G[ss] = 1;
		q.push(mp(beginWord, 1));
		vis[beginWord] = 1;
		while (q.size()) {
			psi t = q.front();
			q.pop();
			if (t.F == endWord) return t.S;
			for (int i = 0; i < t.F.size(); ++i)
				for (int j = 0; j < 26; ++j) {
					string ss = t.F;
					ss[i] = 'a' + j;
					if (G.find(ss) != G.end() && !vis[ss]) {
						q.push(mp(ss, t.S + 1));
						vis[ss] = 1;
					}
				}
		}
		return 0;
    }
};