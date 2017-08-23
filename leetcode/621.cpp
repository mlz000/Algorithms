class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> G;
        int cnt = 0;
        for(auto e : tasks){
            G[e]++;
            cnt = max(cnt, G[e]);
        }
        int ans = (cnt - 1) * (n + 1);
        for(auto e : G) if(e.second == cnt) ans++;
        return max((int)tasks.size(), ans);
    }
};