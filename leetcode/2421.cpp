#define eb emplace_back
#define mp make_pair
const int N = 3e4 + 5;
int f[N], mx[N], cnt[N];
vector<int> g[N];
class Solution {
public:
    int find(int x) {
        return f[x] == x ? x : f[x] = find(f[x]);
    }
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        memset(g, 0, sizeof(g));
        for (const auto& e : edges) {
            g[e[0] + 1].eb(e[1] + 1);
            g[e[1] + 1].eb(e[0] + 1);
        }
        for (int i = 0; i < vals.size(); ++i) {
            f[i + 1] = i + 1;
            mx[i + 1] = vals[i];
            cnt[i + 1] = 1;
            a.eb(mp(vals[i], i + 1));
        }
        sort(a.begin(), a.end());
        int ans = 0;
        for (const auto& pi : a) {
            int value = pi.first;
            int u = pi.second;
            int fu = find(u);
            for (auto v : g[u]) {
                if (vals[v - 1] > vals[u - 1]) {
                    continue;
                }
                int fv = find(v);
                if (fu == fv) {
                    continue;
                }
                f[fv] = fu;
                if (mx[fv] == mx[fu]) {
                    ans += cnt[fv] * cnt[fu];
                    cnt[fu] += cnt[fv];
                } else {
                    mx[fu] = max(mx[fu], mx[fv]);
                }
            }
        }
        return ans + vals.size();
    }
private:
    vector<pair<int, int>> a;
};
