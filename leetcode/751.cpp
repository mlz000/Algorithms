class Solution {
public:
    string work(unsigned x, unsigned t) {
        int a[4];
        a[3] = x & 255, x >>= 8, a[2] = x & 255, x >>= 8, a[1] = x & 255, x >>= 8, a[0] = x & 255;
        int l = 33;
        while (t) {
            --l;
            t >>= 1;
        }   
        stringstream ss;
        ss << a[0] << "." << a[1] << "." << a[2] << "." << a[3] << "/" << l;
        return ss.str();
    }
    vector<string> ipToCIDR(string ip, int range) {
        int a[4];
        sscanf(ip.c_str(), "%d.%d.%d.%d", &a[0], &a[1], &a[2], &a[3]);
        unsigned x = 0;
        x |= a[0], x <<= 8, x |= a[1], x <<= 8, x |= a[2], x <<= 8, x |= a[3];
        vector<string> ans;
        while (range) {
            unsigned t = x & -x;
            while (t > range)   t >>= 1;
            string s = work(x, t);
            ans.push_back(s);
            x += t;
            range -= t;
        }
        return ans;
    }
};