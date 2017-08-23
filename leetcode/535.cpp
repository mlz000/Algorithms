class Solution {
    vector<string> indexEncodes; 
    const string base = "http://tinyurl.com/";
    
    public:
    char map62(int x) {
        if(x < 10) return (char)('0' + x);
        else if(x < 36) return (char)(x + 'a' - 10);
        else return (char)(x + 'A' - 36);
    }
    
    int rev62(char c) {
        if(c >= '0' && c <= '9') return (c - '0');
        else if(c >= 'a' && c <= 'z') return (c - 'a' + 10);
        else if(c >= 'A' && c <= 'Z') return (c - 'A' + 36);
    }
    
    string encode62(int x){
        string res;
        while(x) {
            int rem = x % 62;
            res += map62(rem);
            x /= 62;
        }
        return res;
    }
    
    int decode62(string s) {
        int x = 0;
        for(int i = s.size() - 1; i >= 0; i--) {
            x *= 62;
            x += rev62(s[i]);
        }
        return x;
    }

    string encode(string longUrl) {
        indexEncodes.push_back(longUrl);
        return base + encode62(indexEncodes.size() - 1);
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return indexEncodes[decode62(shortUrl.substr(19))];
    }
};