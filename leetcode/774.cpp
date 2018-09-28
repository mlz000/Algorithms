const double eps = 1e-7;
class Solution {
public:
    double minmaxGasDist(vector<int>& stations, int K) {
        double l = 0.0, r = 1e8;
        for (int i = 0; i < 100; ++i) {
            double m = (l + r) * 0.5;
            int tot = K;
            for (int j = 0; j < stations.size() - 1; ++j) {
                double d = stations[j + 1] - stations[j];
                int now = floor((d + 1e-8) / m);
                tot -= now;
            }
            if (tot >= 0)   r = m;
            else l = m;
        }
        return l;
    }
};