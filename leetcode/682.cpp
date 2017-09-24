#define pb push_back
const int inf = 1000000;
vector<int> now;
class Solution {
public:
    int calPoints(vector<string>& ops) {
        int ans = 0;
        now.clear();
        for (int i = 0; i < ops.size(); ++i) {
            int x = 0;
            if (ops[i][0] == '+')  {
                int sz = now.size();
                x = now[sz - 2] + now[sz - 1];
                now.pb(x);
            }
            else if (ops[i][0] == 'D') {
                int sz = now.size();
                x = now[sz - 1];
                now.pb(x * 2);
            }
            else if (ops[i][0] == 'C') now.pop_back();
            else {
                x = stoi(ops[i]);
                now.pb(x);
            }
        }
        for (auto& x : now) ans += x;
        return ans;
    }
};