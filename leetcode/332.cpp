#define pb push_back
#define F first 
#define S second
class Solution {
public:
    vector<string> findItinerary(vector<pair<string, string> > s) {
        for (auto x : s)    G[x.F].insert(x.S);
        dfs("JFK");
        reverse(ans.begin(), ans.end());
        return ans;
    }
    void dfs(string u) {
        while (G[u].size()) {
            string v = *G[u].begin();
            G[u].erase(G[u].begin());
            dfs(v);
        }
        ans.pb(u);
    }
private:
    map<string, multiset<string> > G;
    vector<string> ans;
};