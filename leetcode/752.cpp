class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_map<string, int> v, step;
        for (auto s : deadends) v[s] = 1;
        step["0000"] = 0;
        queue<string> q;
        q.push("0000");
        while (q.size()) {
            string t = q.front();
            if (t == target)   return step[t];
            q.pop();
            if (v[t])   continue;
            for (int i = 0; i < 4; ++i) {
                string s = t;
                char c = s[i];
                int x = c - '0';
                int a = (x + 1) % 10, b = (x + 9) % 10;
                s[i] = '0' + a;
                if (!v[s] && !step.count(s)) {
                    step[s] = step[t] + 1;
                    q.push(s);
                }
                s[i] = '0' + b;
                if (!v[s] && !step.count(s)) {
                    step[s] = step[t] + 1;
                    q.push(s);
                }                
            }
        }
        return -1;
    }
};