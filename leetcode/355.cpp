#define pb push_back
#define mp make_pair
#define F first
#define S second
typedef pair<int, int> pii;
class Twitter {
public:
    Twitter() {
        cnt = 0;
    }
    void postTweet(int userId, int tweetId) {
        po[userId].insert(mp(-(++cnt), tweetId));  
        fo[userId].insert(userId);
    }
    vector<int> getNewsFeed(int userId) {
        set<pii> q;
        vector<int> ans;
        for (auto x : fo[userId]) {
            int n = min((int)po[x].size(), 10);
            auto it = po[x].begin();
            while (n--) {
                if (q.size() < 10)    q.insert(*it++);
                else {
                    auto it2 = q.end();
                    if (*it < *(--it2))   q.erase(it2), q.insert(*it++);
                }
            }
        }
        for (auto x : q)    ans.pb(x.S);
        return ans;
    }
    void follow(int followerId, int followeeId) {
        fo[followerId].insert(followeeId);
    }
    void unfollow(int followerId, int followeeId) {
        if (followerId == followeeId)   return;
        fo[followerId].erase(followeeId);
    }
private:
    int cnt;
    unordered_map<int, set<int> > fo;
    unordered_map<int, set<pii> > po;
};