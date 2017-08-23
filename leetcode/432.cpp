#define pb push_back
class AllOne {
public:
    unordered_map<string, int> G;
    vector<list<string> > fre;
    AllOne() {
    }
    void inc(string key) {
        if (G.find(key) != G.end()) ++G[key];
        else G[key] = 1;
        int x = G[key] - 1;
        if (x)  fre[x].remove(key);
        if (fre.size() <= x + 1)    fre.resize(x + 2);
        fre[x + 1].pb(key);
    }
    void dec(string key) {
        if (G.find(key) == G.end()) return;
        else {
            int x = --G[key];
            if (x == 0) G.erase(key);
            fre[x + 1].remove(key);
            fre[x].pb(key);
        }
    }
    string getMaxKey() {
        for (int i = fre.size() - 1; i > 0; --i){
            if(fre[i].size())   return fre[i].front();
        }
        return "";
    }
    string getMinKey() {
        for (int i = 1; i < fre.size(); ++i){
            if(fre[i].size())   return fre[i].front();
        }
        return "";
    }
};