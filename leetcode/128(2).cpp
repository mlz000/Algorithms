class Solution {
public:
    unordered_map<int, int> f, sz;
    int find(int x) {
        return f[x] == x ? x : f[x] = find(f[x]);
    }
    int longestConsecutive(vector<int>& nums) {
        int ans = 0;
        for (auto& x : nums) {
            if (f.count(x)) continue;
            f[x] = x;
            sz[x] = 1;
            if (f.count(x - 1)) {
                int fy = find(x - 1);
                f[x] = fy;
                ++sz[fy];
            }
            if (f.count(x + 1)) {
                int fx = find(x);
                int fy = find(x + 1);
                f[fx] = fy;
                sz[fy] += sz[fx];
            }
            ans = max(ans, sz[find(x)]);
        }
        return ans;
    } 
};