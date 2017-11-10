// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    int read(char *buf, int n) {
        char tmp[4];
        int now = 0;
        while (n > 0) {
            int cnt = min(n, read4(tmp));
            if (cnt == 0)   return now;
            for (int i = 0; i < cnt; ++i)   buf[now++] = tmp[i];
            n -= cnt;
        }
        buf[now] = '\0';
        return now;
    }
};