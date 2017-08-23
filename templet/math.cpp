//线性逆元 
void init(){
	inv[0] = inv[1] = fac[0] = fac[1] = rfac[0] = rfac[1] = 1ll;
	for(int i = 2; i < N; ++i){
		inv[i] = (M - M / i) * inv[M % i] % M;
		fac[i] = fac[i - 1] * i % M;
		rfac[i] = rfac[i - 1] * inv[i] % M;
	}
}
//扩展欧几里得
void gcd(LL a,LL b,LL &d,LL &x,LL &y){
	if(!b){d=a;x=1;y=0;return;}
	gcd(b,a%b,d,y,x),y-=x*(a/b);
}
//lucas c[n][m] % p
LL lucas(LL x, LL y) {  
    LL ans = 1;  
    while(x && y) {  
        LL a = x % M;  
        LL b = y % M;  
        if(a < b) return 0;  
        ans = (ans * fac[a] * P(fac[b] * fac[a - b] % M, M - 2)) % M;
        x /= M;  
        y /= M;  
    }  
    return ans;  
}
//BSGS	a^x=b(mod n)
int bsgs(int a,int b){
	int m;
	LL e=1ll,v;
	m=(int)sqrt(M+0.5);
	v=inv(P(a,m));
	map<int,int>x;
	x[1]=0;
	for(int i=1;i<m;++i){
		e=e*a%M;
		if(!x.count(e))	x[e]=i;
	}
	for(int i=0;i<m;++i){
		if(x.count(b))	return i*m+x[b];
		b=v*b%M;
	}
	return -1;
}
//中国剩余定理
LL china(int n,int a[],int m[]){
	LL M=1ll,d,y,x=0ll;
	for(int i=0;i<n;++i)	M*=m[i];
	for(int i=0;i<n;++i){
		LL w=M/m[i];
		gcd(m[i],w,d,d,y);
		x=(x+y*w*a[i])%M;
	}
	return (x+M)%M;
}
//线性筛+Euler+Mobius
void init(){
	f[1] = mu[1] = 1;
	for (int i = 2; i <= 50000; ++i){
		if(!check[i])	p[++tot] = i, f[i] = i - 1, mu[i] = -1;
		for (int j = 1; j <= tot; ++j){
			if (i * p[j] > 50000)	break;
			check[i * p[j]] = true;
			if (i % p[j] == 0) {
				f[i * p[j]] = f[i] * p[j];
				mu[i * p[j]] = 0;
				break;
			}
			else mu[i*p[j]] = -mu[i], f[i * p[j]] = f[i] * (p[j] - 1);
		}
	}
}
//sieve O(N^3/4)
#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll f[340000],g[340000],n;
void init(){
    ll i,j,m;
    for(m=1;m*m<=n;++m)f[m]=n/m-1;
    for(i=1;i<=m;++i)g[i]=i-1;
    for(i=2;i<=m;++i){
        if(g[i]==g[i-1])continue;
        for(j=1;j<=min(m-1,n/i/i);++j){
            if(i*j<m)f[j]-=f[i*j]-g[i-1];
            else f[j]-=g[n/i/j]-g[i-1];
        }
        for(j=m;j>=i*i;--j)g[j]-=g[j/i]-g[i-1];
    }
}
int main(){
    while(scanf("%I64d",&n)!=EOF){
        init();
        printf("%lld\n",f[1]);
    }
    return 0;
}
//Meissel-Lehmer O(N^2/3)
#define MAXN 100
#define MAXM 50010
#define MAXP 166666
#define MAX 1000010
#define clr(ar) memset(ar, 0, sizeof(ar))
#define read() freopen("lol.txt", "r", stdin)
#define dbg(x) cout << #x << " = " << x << endl
#define chkbit(ar, i) (((ar[(i) >> 6]) & (1 << (((i) >> 1) & 31))))
#define setbit(ar, i) (((ar[(i) >> 6]) |= (1 << (((i) >> 1) & 31))))
#define isprime(x) (( (x) && ((x)&1) && (!chkbit(ar, (x)))) || ((x) == 2))

using namespace std;

namespace pcf{
    long long dp[MAXN][MAXM];
    unsigned int ar[(MAX >> 6) + 5] = {0};
    int len = 0, primes[MAXP], counter[MAX];

    void Sieve(){
        setbit(ar, 0), setbit(ar, 1);
        for (int i = 3; (i * i) < MAX; i++, i++){
            if (!chkbit(ar, i)){
                int k = i << 1;
                for (int j = (i * i); j < MAX; j += k) setbit(ar, j);
            }
        }

        for (int i = 1; i < MAX; i++){
            counter[i] = counter[i - 1];
            if (isprime(i)) primes[len++] = i, counter[i]++;
        }
    }

    void init(){
        Sieve();
        for (int n = 0; n < MAXN; n++){
            for (int m = 0; m < MAXM; m++){
                if (!n) dp[n][m] = m;
                else dp[n][m] = dp[n - 1][m] - dp[n - 1][m / primes[n - 1]];
            }
        }
    }

    long long phi(long long m, int n){
        if (n == 0) return m;
        if (primes[n - 1] >= m) return 1;
        if (m < MAXM && n < MAXN) return dp[n][m];
        return phi(m, n - 1) - phi(m / primes[n - 1], n - 1);
    }

    long long Lehmer(long long m){
        if (m < MAX) return counter[m];

        long long w, res = 0;
        int i, a, s, c, x, y;
        s = sqrt(0.9 + m), y = c = cbrt(0.9 + m);
        a = counter[y], res = phi(m, a) + a - 1;
        for (i = a; primes[i] <= s; i++) res = res - Lehmer(m / primes[i]) + Lehmer(primes[i]) - 1;
        return res;
    }
}

int main()
{
    pcf::init();
    long long n;
    while(cin>>n)
    cout<<pcf::Lehmer(n)<<endl;
}
//zeller 
int zeller(int y,int m,int d){
	if(m<=2)	y--,m+=12;
	int c=y/100;
	y%=100;
	int w=((c>>2)-(c<<1)+y+(y>>2)+(13*(m+1)/5)+d-1)%7;
	if(w<0)	w+=7;
	return w;
}
//Newton迭代
x1 = x0 - func(x0) / func1(x0)	//f(x)=0 func(x)为原方程 func1(x)为导数方程
// FWT
void trans(int l, int r){
	if(l == r - 1)	return ;
	int len = (r - l) / 2;
	int mid = l + len;
	trans(l, mid), trans(mid, r);
	for (int i = l; i < mid; ++i){
		ll x1 = (a[i] - a[i + len] + M) % M, x2 = (a[i] + a[i + len]) % M;
		a[i] = x1,a[i + len] = x2;
	}
}
void reverse(int l, int r){
	if (r - l == 1)	return ;
	int len = (r - l) / 2;
	int mid = l + len;
	for(int i = l; i < mid; ++i){
		ll x1 = a[i], x2 = a[i + len];
		a[i] = (x1 + x2) * inv2 % M;
		a[i + len] = (x2-x1)* inv2 % M;
	}
	reverse(l, mid), reverse(mid, r);
}
//Pollard rho + Miller Rabin
LL mul(LL a, LL b, LL p) {
	LL t = (a * b - (LL)((long double)a * b / p  + 0.05) * p);
	return t < 0 ? t + p : t;
}
LL P(LL x, LL y, LL p) {
	if (y == 0)	return 1 % p;
	LL t = 1ll;
	x = x % p;
	for (; y; y >>= 1ll) {
		if (y & 1ll)	t = mul(t, x, p);
		x = mul(x, x, p);
	}
	return t;
}
bool check(LL a, LL n, LL r, LL s) {
	LL t = P(a, r, n), p = t;
	for (int i = 1; i <= s; ++i) {
		t = mul(t, t, n);
		if (t == 1 && p != 1 && p != n - 1)	return 1;
		p = t;
	}
	if (t != 1)	return 1;
	return 0;
}
LL Pollard_rho(LL n, LL c) {
	LL k = 2, x = rand() % n, y = x, p = 1;
	for (LL i = 1; p == 1; ++i){
		++i;
		x = (mul(x, x, n) + c) % n;
		p = y > x ? y - x : x - y;
		p = __gcd(p, n);
		if (i == k)	y = x, k <<= 1ll;
	}
	return p;
}
bool Miller_Rabin(LL n) {
	if (n < 2)	return 0;
	if (n == 2)	return 1;
	if ((n % 2) == 0)	return 0;
	LL r = n - 1, s = 0;
	while ((r % 2) == 0) r >>= 1ll, ++s;
	for (int i = 0; i < 10; ++i) {
		if (p[i] >= n)	continue;
		if (check(p[i], n, r, s))	return 0;
	}
	return 1;
}
void find(LL n) {
	if (Miller_Rabin(n)) {
		factor[tol++] = n;
		return;
	}
	LL t = n;
	while (t >= n)	t = Pollard_rho(t, rand() % (n - 1) + 1);
	find(t);
	find(n / t);
}
