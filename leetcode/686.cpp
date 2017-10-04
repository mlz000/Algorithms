/*
 Given two strings A and B, find the minimum number of times A has to be repeated such that B is a substring of it. If no such solution, return -1.

For example, with A = "abcd" and B = "cdabcdab".

Return 3, because by repeating A three times (¡°abcdabcdabcd¡±), B is a substring of it; and B is not a substring of A repeated two times ("abcdabcd").

Note:
The length of A and B will be between 1 and 10000.
 */
class Solution {
public:
    int repeatedStringMatch(string A, string B) {
        int l = 1, r = B.size() / A.size() + 10, ans = -1;
        if (A.find(B) != std::string::npos) return 1;
        if ((A + A).find(B) != std::string::npos)   return 2;
        while (l <= r) {
            int m = l + r >> 1;
            string now = "";
            for (int i = 0; i < m; ++i) now += A;
                if (now.find(B) != std::string::npos)   ans = m, r = m - 1;
            else l = m + 1;
        }
        return ans;
    }
};
