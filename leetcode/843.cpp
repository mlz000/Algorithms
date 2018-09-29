/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Master {
 *   public:
 *     int guess(string word);
 * };
 */
class Solution {
public:
    int ma[101][101];
    int dis(string x, string y) {
        int t = 0;
        for (int i = 0; i < x.size(); ++i)
            t += x[i] == y[i];
        return t;
    }
    void findSecretWord(vector<string>& w, Master& master) {
        unordered_set<string> S(w.begin(), w.end());
        vector<string> list = w;
        for (int i = 0; i < 10; ++i) {
            string now = list[rand() % list.size()];
            int d = master.guess(now);
            for (auto it = S.begin(); it != S.end();) {
                if (dis(*it, now) != d) {
                    it = S.erase(it);
                }
                else ++it;
            }
            list.clear();
            for (auto s: S) list.push_back(s);
        }
    }
};