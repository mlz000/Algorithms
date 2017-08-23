class MinskyMystery {
public:
  int computeAnswer(long long);
};
 
const long long md = (long long)(1e9 + 9);
 
int MinskyMystery::computeAnswer(long long N) {
  if (N < 2) return -1;
  long long x = 2, ans = 0;
  while (N % x != 0 && x*x <= N) x++;
  if (x*x > N) x = N;
  long long L = 2, R = x-1;
  while (L <= R && L <= 1000000) {
    ans = (ans + (N-1)/L) % md;
    L++;
  }
  long long d, lg, rg;
  if (L <= R)
    for (d=1;d<=1000000;d++) {
      lg = (N+d)/(d+1);
      rg = (N-1)/d;
      if (L > lg) lg = L;
      if (R < rg) rg = R;
      if (lg <= rg) ans = (ans + (rg-lg+1)*d) % md;
    }
  ans = (ans + ((4*N+1) % md)*((x-2) % md) + 3*N + N/x + x) % md;
  return ans;
}
 
