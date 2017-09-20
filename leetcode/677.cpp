class MapSum {
public:
    unordered_map<string, int> G;
    MapSum() {
      G.clear();
    }
    
    void insert(string key, int val) {
        G[key]=val;
    }
    
    int sum(string prefix) {
      int ans;
      ans = 0;
      for (auto it = G.begin(); it != G.end(); it++) {
        if ((it -> first.length() >= prefix.length()) && (it -> first.substr(0, prefix.length()) == prefix))
          ans += it -> second;
      }
      return ans;
    }
};