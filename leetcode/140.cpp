#define pb push_back
class Solution {
	public:
	vector<string> dp(string s) {
		if (ans.count(s))	return ans[s];
		int l = s.size(); 
		vector<string> now;
		if (dict[s])	now.pb(s);
		for (int i = 1; i <= l; ++i) {
			string t = s.substr(0, i);
			if (dict[t]) {
				vector<string> tmp = dp(s.substr(i));
				int sz = tmp.size();
				for (int j = 0; j < sz; ++j) {
					string ss = t + " " + tmp[j];
					now.pb(ss);
				}
			}
		}
		return ans[s] = now;
	}
    vector<string> wordBreak(string s, vector<string>& wordDict) {
    	sz = s.size();
		for (auto ss : wordDict)	dict[ss] = 1;
		return dp(s);
    }
	private:
	map<string, bool> dict;
	map<string, vector<string> > ans;
	int sz;
};