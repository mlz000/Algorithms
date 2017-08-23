class Solution {
public:
    string fractionAddition(string expression) {
        istringstream in(expression);
        int a = 0, b = 1, x, y;
        char s;
        while (in >> x >> s >> y) {
            a = a * y + b * x;
            b *= y;
            int g = abs(__gcd(a, b));
            a /= g, b /= g;
        }
        return to_string(a) + '/' + to_string(b);
    }
};