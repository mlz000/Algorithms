class Solution {
public:
    int l[101], r[101];
    vector<int> pourWater(vector<int>& h, int V, int K) {
        int n = h.size();
        for (int i = 1; i <= V; ++i) {
            int p = K;
            ++h[p];
            while (1) {
                int p2 = -1, p3 = -1;
                for (int j = p - 1; j >= 0; --j) {
                    if (h[j] >= h[p])    break;
                    else if (h[j] < h[p] - 1) {
                        p2 = j;
                        break;
                    }
                }
                if (p2 != -1) {
                    ++h[p2];
                    --h[p];
                    p = p2;
                }
                for (int j = p + 1; j < n; ++j) {
                    if (h[j] >= h[p])    break;
                    else if (h[j] < h[p] - 1) {
                        p3 = j;
                        break;
                    }
                }
                if (p2 == -1 && p3 != -1) {
                    ++h[p3];
                    --h[p];
                    p = p3;
                }
                if (p2 == -1 && p3 == -1)   break;
            }
        }
        return h;
    }
};