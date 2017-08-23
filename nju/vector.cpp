#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
class Vector {
    int cnt, maxcnt, *p;
    public:
    Vector() {
        cnt = 0;
        maxcnt = 1;
        p = (int*)malloc(sizeof(int));
    }
	~Vector() {
		free(p);
	}
    inline int size() const{
        return cnt;
    }
    inline int capacity() const{
        return maxcnt;
    }
    int& operator[] (int x) {
        return p[x];
    }
    void push_back(int x) {
        if(size() == capacity())    reserve(capacity()<<1);
        p[cnt++] = x;
    }
    void pop_back() {
        --cnt;
    }
    void reserve(int n) {
        if (n <= capacity()) return ;
        maxcnt = n;
        int* q = (int*)malloc(maxcnt*sizeof(int));
        for (int i = 0; i < size(); ++i) q[i] = p[i];
        free(p);
        p = q;
    }
    void resize(int n, int x = 0) {
        while (size() < n)   push_back(x);
        while(n > size())    pop_back();
    }
    Vector& operator= (const Vector &b) {
        cnt = b.cnt;
        maxcnt = b.maxcnt;
        free(p);
        p = (int*)malloc(cnt * sizeof(int));
        memcpy(p, b.p, sizeof(p));
        return *this;
    }
    bool operator== (const Vector &b) {
        if (size() != b.size()) return 0;
        for (int i = 0; i < size(); ++i) 
            if (p[i] != b.p[i]) return 0;
        return 1;
    }
};
int main() {
    int n, m, x;
    while (scanf("%d%d", &n, &m) != EOF) {
        Vector a;
        a.reserve(n);
        for (int i = 0; i < m; ++i) {
            scanf("%d", &x);
            a.push_back(x);
        }
        for (int i = 0; i < a.size(); ++i)   printf("%d%s",a[i], i == m - 1 ? "\n" : " ");
        printf("%d %d\n", a.size(), a.capacity());
    }
    return 0;
}
