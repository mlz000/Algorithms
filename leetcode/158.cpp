// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    int lasti = 0, last = 0;
    char tmp[4];
    int read(char *buf, int n) {
        int i = 0, now = 0;
        while (n > 0) {
            if (last != 0) {
                int t = min(n, last);
                n -= t;
                last -= t;
                while (t--) buf[i++] = tmp[lasti++];
            }
            else {
                last = read4(tmp);
                if (last == 0)  break;
                int t = min(n, last);
                n -= t;
                last -= t;
                lasti = 0;
                while(t--) buf[i++] = tmp[lasti++];
            }
        }
        return i;
    }
};