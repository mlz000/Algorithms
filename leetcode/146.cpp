#define F first
#define S second
class LRUCache {
public:
	unordered_map<int, list<pair<int, int>>::iterator> mp;  
	list<pair<int, int> > cache;  
	int size;  
    LRUCache(int capacity) {
        size = capacity;
    }   
    int get(int key) {
        auto it = mp.find(key);
		if (it == mp.end())	return -1;
		cache.splice(cache.begin(), cache, it -> S);
		return it -> S -> S;
    }
    void put(int key, int value) {
        auto it = mp.find(key);
		if (it != mp.end()) {
			it -> S -> S = value;
			return cache.splice(cache.begin(), cache, it -> S);
		}
		cache.insert(cache.begin(), make_pair(key, value));
		mp[key] = cache.begin();
		if (cache.size() > size)	mp.erase(cache.back().F), cache.pop_back();
    }
};
