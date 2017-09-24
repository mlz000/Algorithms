/*
681. Next Closest Time My SubmissionsBack to Contest
User Accepted: 992
User Tried: 1133
Total Accepted: 1010
Total Submissions: 2698
Difficulty: Medium
Given a time represented in the format "HH:MM", form the next closest time by reusing the current digits. There is no limit on how many times a digit can be reused.

You may assume the given input string is always valid. For example, "01:34", "12:09" are all valid. "1:34", "12:9" are all invalid.

Input: "23:59"
Output: "22:22"
Explanation: The next closest time choosing from digits 2, 3, 5, 9, is 22:22. It may be assumed that the returned time is next day's time since it is smaller than the input time numerically.

*/
map<int, bool> ok;
class Solution {
public:
    string nextClosestTime(string time) {
        ok.clear();
        int a = stoi(time.substr(0, 2));
        int b = stoi(time.substr(3, 2));
        ok[a % 10] = ok[a / 10] = ok[b % 10] = ok[b / 10] = 1;
        for (int i = 0; i < 24; ++i)
            for (int j = 0; j <= 60; ++j) {
                if (!i && !j)   continue;
                int mm = (b + j) % 60;
                int hh = (a + i + (b + j) / 60) % 24;
                if (hh < 10 && !ok[0] || (mm < 10 && !ok[0]))   continue;
                if (ok[mm % 10] && ok[mm / 10] && ok[hh % 10] && ok[hh / 10]) {
                    char s[20];
                    sprintf(s, "%02d:%02d", hh, mm);
                    return string(s);
                }
            }
    }
};