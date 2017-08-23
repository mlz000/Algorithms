#define F first 
#define S second
class LFUCache {
	public:
	int size, mn;
    LFUCache(int capacity) {
        size = capacity;
		mn = 0;
    }
    int get(int key) {
        if (!mp.count(key))	return -1;
		fr[mp[key].S].erase(lfu[key]);
		++mp[key].S;
		fr[mp[key].S].push_front(key);
		lfu[key] = fr[mp[key].S].begin();
		if (!fr[mn].size())	++mn;
		return mp[key].F;
    }
    void put(int key, int value) {
		if (!size)	return;
        if (~get(key))	mp[key].F = value;
    	else {
			if (mp.size() == size) {
				int t = fr[mn].back();
				fr[mn].pop_back();
				lfu.erase(t);
				mp.erase(t);
			}
			mp[key] = make_pair(value, 1);
			fr[mn = 1].push_front(key);
			lfu[key] = fr[1].begin();
		}
	}
	unordered_map<int, list<int>::iterator> lfu;
	unordered_map<int, pair<int, int> > mp;//key value frequency
	unordered_map<int, list<int> > fr;
};
