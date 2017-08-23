#define pb push_back
#define mp make_pair
#define F first
#define S second
typedef pair<int, int> pii;
class RandomizedCollection {
public:
    unordered_map<int, vector<int> > G;
    vector<pii> a;
    RandomizedCollection() {
    }
    bool insert(int val) {
        bool ok = G.find(val) == G.end();
        a.pb(mp(val, G[val].size())), G[val].pb(a.size() - 1);
        return ok;
    }
    bool remove(int val) {
        bool ok = G.find(val) != G.end();
        if (ok) {
            pii t = a.back();
            G[t.F][t.S] = G[val].back();
            a[G[val].back()] = t;
            G[val].pop_back();
            if (!G[val].size()) G.erase(val);
            a.pop_back();
        }
        return ok;
    }
    int getRandom() {
        return a[rand() % a.size()].F;
    }
};