#define pb push_back
unordered_map<string, vector<string> > G;
vector<vector<string> > ans;
class Solution {
public:
    string work(string s) {
        string t = "";
        for (int i = 1; i < s.size(); ++i) {
            int now = s[i] - s[i - 1];
            if (now < 0)   now += 26;
            t += 'a' + now;
        }
        return t;
    }
    
    vector<vector<string>> groupStrings(vector<string>& s){
        G.clear();
        ans.clear();
        for(auto& ss : s) {
            G[work(ss)].pb(ss);
        }
        for (auto& t : G) {
            ans.pb(vector<string>());
            for (auto& ss : t.second)  ans[ans.size() - 1].pb(ss);
        }
        return ans;
    }
};