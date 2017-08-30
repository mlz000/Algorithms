#define F first
#define S second
#define pb push_back
class Solution {
public:
    unordered_map<string, string> f;
    unordered_map<string, double> dep;
    string find(string x) {
        if (f[x] == x)  return x;
        string fa = f[x];
        f[x] = find(fa);
        dep[x] *= dep[fa];
        return f[x];
    }
    void merge(string a, string b, double x) {
        string fa = find(a), fb = find(b);
        if (fa != fb) {
            f[fb] = fa;
            dep[fb] = dep[a] / (x * dep[b]); 
        }
    }
    vector<double> calcEquation(vector<pair<string, string>> eq, vector<double>& v, vector<pair<string, string>> q) {
        for (auto& t : eq)  f[t.F] = t.F, f[t.S] = t.S, dep[t.F] = dep[t.S] = 1.0;
        for (int i = 0; i < eq.size(); ++i) merge(eq[i].F, eq[i].S, v[i]);
        vector<double> ans;
        for (auto& t : q) {
            if (!f.count(t.F) || !f.count(t.S)) {
                ans.pb(-1.0);
                continue;
            }
            string fa = find(t.F), fb = find(t.S);
            if (fa != fb)   ans.pb(-1.0);
            else ans.pb(dep[t.F] / dep[t.S]);
        }
        return ans;
    }
};