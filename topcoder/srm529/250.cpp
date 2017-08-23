#include <bits/stdc++.h>
using namespace std;
class KingSort {
public:
  vector <string> getSortedList(vector <string>);
};
 
string ones[99], tens[99];
string name[99], sid[99];
int id[99];
 
vector <string> KingSort::getSortedList(vector <string> s) {
  ones[0] = ""; ones[1] = "I"; ones[2] = "II"; ones[3] = "III"; ones[4] = "IV";
  ones[5] = "V"; ones[6] = "VI"; ones[7] = "VII"; ones[8] = "VIII"; ones[9] = "IX";
  tens[0] = ""; tens[1] = "X"; tens[2] = "XX"; tens[3] = "XXX"; tens[4] = "XL"; tens[5] = "L";
  int n = s.size(), i, j, tt;
  string tmp;
  for (i=0;i<n;i++) {
    stringstream ss(s[i]);
    ss >> name[i] >> sid[i];
    id[i] = 0;
    for (j=1;j<=50;j++) {
      string st = tens[j/10]+ones[j%10];
      if (st == sid[i]) id[i] = j;
    }
  }
  for (i=0;i<n;i++)
    for (j=i+1;j<n;j++)
      if (name[i] > name[j] || name[i] == name[j] && id[i] > id[j]) {
        tmp = name[i]; name[i] = name[j]; name[j] = tmp;
        tmp = sid[i]; sid[i] = sid[j]; sid[j] = tmp;
        tt = id[i]; id[i] = id[j]; id[j] = tt;
      }
  vector <string> ret;
  ret.clear(); 
  for (i=0;i<n;i++) ret.push_back(name[i]+" "+sid[i]);
  return ret;
}
