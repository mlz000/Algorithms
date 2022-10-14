const int N = 1e6 + 10;
int son[N][27], cnt[N], last;
int new_node() {
    ++last;
    memset(son[last], 0, sizeof(son[last]));
    cnt[last] = 0;
    return last;
}
class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        last = 0;
        int rt = new_node();
        for (auto& s : words) {
            int p = rt;
            for (auto& c : s) {
                int k = c - 'a';
                if (!son[p][k]) son[p][k] = new_node();
                p = son[p][k];
                ++cnt[p];
            }
        }
        vector<int> ans;
        for (auto& s : words) {
            int p = rt;
            int sum = 0;
            for (auto& c : s) {
                int k = c - 'a';
                p = son[p][k];
                sum += cnt[p];
            }
            ans.push_back(sum);
        }
        return ans;
        
    }
};


