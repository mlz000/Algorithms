class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& a) {
        vector<int> cnt(n);
        multiset<pair<long long, int> > used;
        set<int> free;
        sort(a.begin(), a.end());
        for (int i = 0; i < n; ++i) {
            free.insert(i);
        }
        for (int i = 0; i < a.size(); ++i) {
            // have more rooms to reuse
            while (used.size() && used.begin() -> first <= a[i][0]) {
                free.insert(used.begin() -> second);
                used.erase(used.begin());
            }
            if (free.size()) {
                int t = *free.begin();
                free.erase(free.begin());
                used.insert(make_pair(a[i][1], t));
                ++cnt[t];
            } else {
                //delay
                int t = used.begin() -> second;
                long long end_time = used.begin() -> first;
                used.erase(used.begin());
                used.insert(make_pair(end_time + a[i][1] - a[i][0], t));
                ++cnt[t];
            }
        }
        int mx = -1, pos;
        for (int i = 0; i < n; ++i) {
            if (cnt[i] > mx) {
                mx = cnt[i];
                pos = i;
            }
        }
        return pos;
    }
};
