const int N = 404;
#define eb emplace_back
class Solution {
public:
    vector<int> toposort(vector<vector<int>> graph, vector<int> degree, int k) {
        queue<int> q;
        vector<int> ans(k + 1);
        for (int i = 1; i <= k; ++i) {
            if (!degree[i]) {
                q.push(i);
            }
        }
        int cnt = -1;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            ans[u] = ++cnt;
            for (auto v : graph[u]) {
                --degree[v];
                if (!degree[v]) {
                    q.push(v);
                }
            }
        }
        if (cnt != k - 1) return {};
        return ans;
    }
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<int> indegree_row(k + 1, 0), indegree_col(k + 1, 0);
        vector<vector<int>> graph_row(k + 1, vector<int>(k + 1, 0)), graph_col(k + 1, vector<int>(k + 1, 0));
        vector<vector<int>> ans(k, vector<int>(k, 0));
        for (auto row : rowConditions) {
            graph_row[row[0]].eb(row[1]);
            ++indegree_row[row[1]];
        }
        int cur_row = 0, cur_col = 0, cnt_row = 0, cnt_col = 0;
        for (auto col : colConditions) {
            graph_col[col[0]].eb(col[1]);
            ++indegree_col[col[1]];
        }
        auto rk_row = toposort(graph_row, indegree_row, k);
        if (rk_row.empty()) return {};
        auto rk_col = toposort(graph_col, indegree_col, k);
        if (rk_col.empty()) return {};
        for (int i = 1; i <= k; ++i) {
            ans[rk_row[i]][rk_col[i]] = i;
        }
        return ans;
    }
};
