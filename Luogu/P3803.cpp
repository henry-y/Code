#include <algorithm>
#include <cstdio>
#include <cmath>
using namespace std;

#define ll long long
const int N = 3e6 + 10;
const double PI = acos(-1.0);

namespace io {
char buf[1<<21], *p1 = buf, *p2 = buf;
inline char gc() {
    if(p1 != p2) return *p1++;
    p1 = buf;
    p2 = p1 + fread(buf, 1, 1 << 21, stdin);
    return p1 == p2 ? EOF : *p1++;
}
#define G gc

#ifndef ONLINE_JUDGE
#undef G
#define G getchar
#endif

template<class I>
inline void read(I &x) {
    x = 0; I f = 1; char c = G();
    while(c < '0' || c > '9') {if(c == '-') f = -1; c = G(); }
    while(c >= '0' && c <= '9') {x = x * 10 + c - '0'; c = G(); }
    x *= f;
}

template<class I>
inline void write(I x) {
    if(x == 0) {putchar('0'); return;}
    I tmp = x > 0 ? x : -x;
    if(x < 0) putchar('-');
    int cnt = 0;
    while(tmp > 0) {
        buf[cnt++] = tmp % 10 + '0';
        tmp /= 10;
    }
    while(cnt > 0) putchar(buf[--cnt]);
}

#define in(x) read(x)
#define outn(x) write(x), putchar('\n')
#define out(x) write(x), putchar(' ')

} using namespace io;

struct complex {
    double x, y;
    complex(double xx = 0, double yy = 0) {x = xx; y = yy;}
}a[N], b[N]; 
complex operator + (complex a, complex b) {return complex(a.x + b.x, a.y + b.y);}
complex operator - (complex a, complex b) {return complex(a.x - b.x, a.y - b.y);}
complex operator * (complex a, complex b) {return complex(a.x * b.x - a.y * b.y, a.x * b.y + a.y * b.x);  }
complex operator / (complex a, complex b) {double t = b.x * b.x + b.y * b.y; return complex((a.x * b.x + a.y * b.y) / t, (a.y * b.x - a.x * b.y) / t);}
//(a+bi)(c+di)=ac+adi+bci-bd=(ac-bd, (ad+bc)i)

int n, m, limit = 1;
/*
void fft(int len, complex *f, int op) {
    if(len == 1) return;
    complex fl[len >> 1], fr[len >> 1];
    for(int i = 0; i <= len; i += 2) 
        fl[i >> 1] = f[i], fr[i >> 1] = f[i + 1];
    fft(len >> 1, fl, op);
    fft(len >> 1, fr, op);
    complex tmp = complex(cos(2.0 * PI / len), op * sin(2.0 * PI / len)), w = complex(1, 0);
    for(int i = 0; i < (len >> 1); ++i, w = w * tmp) {
        complex t = w * fr[i];
        f[i] = fl[i] + t;
        f[i + (len >> 1)] = fl[i] - t;
    }
}
*/

int rev[N], k;

void fft(complex *f, int type) {
    for(int i = 0; i < limit; ++i) if(i < rev[i]) swap(f[i], f[rev[i]]);
    for(int len = 1; len < limit; len <<= 1) {
        complex wn = complex(cos(PI / len), type * sin(PI / len));
        for(int i = 0; i < limit; i += len << 1) {
            complex w = complex(1, 0);
            for(int j = 0; j < len; ++j, w = w * wn) {
                complex x = f[i + j], y = w * f[i + j + len];
                f[i + j] = x + y;
                f[i + j + len] = x - y;
            }
        }
    }
}

int main() {
    in(n), in(m);
    for(int i = 0; i <= n; ++i) in(a[i].x);
    for(int i = 0; i <= m; ++i) in(b[i].x);
    while(limit <= n + m) limit <<= 1, ++k;
    for(int i = 0; i < limit; ++i) rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (k - 1));
    fft(a, 1);
    fft(b, 1);
    for(int i = 0; i <= limit; ++i) a[i] = a[i] * b[i];
    fft(a, -1);
    for(int i = 0; i <= n + m; ++i) printf("%d ", (int)(a[i].x / limit + 0.5));
} 