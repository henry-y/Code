#include <algorithm>
#include <cstdio>
#include <cmath>
using namespace std;

#define ll long long
const int N = 3e6 + 10;
const double PI = acos(-1.0);

struct complex {
    double x, y;
    complex(double xx = 0, double yy = 0) {x = xx; y = yy;}
}a[N], b[N];

complex operator + (complex a, complex b) {return complex(a.x + b.x, a.y + b.y);}
complex operator - (complex a, complex b) {return complex(a.x - b.x, a.y - b.y);}
complex operator * (complex a, complex b) {return complex(a.x * b.x - a.y * b.y, a.x * b.y + a.y * b.x);}

int n, m, limit = 1;
int rev[N], k, ans[N];
char s[N], t[N];

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
    scanf("%d%s%s", &n, s, t);
    int cnt = 0;
    for(int i = n - 1; i >= 0; --i) a[cnt++].x = s[i] - '0';
    cnt = 0;
    for(int i = n - 1; i >= 0; --i) b[cnt++].x = t[i] - '0';
    while(limit < n * 2) limit <<= 1, ++k;
    for(int i = 0; i < limit; ++i) 
    	rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (k - 1));
    fft(a, 1);
    fft(b, 1);
    for(int i = 0; i <= limit; ++i) a[i] = a[i] * b[i];
    fft(a, -1);
    for(int i = 0; i <= limit; ++i) {
    	ans[i] += (int)(a[i].x / limit + 0.5);
    	if(ans[i] >= 10) {
    		ans[i + 1] += ans[i] / 10;
    		ans[i] %= 10;
    		if(i == limit) ++limit;
    	}
    }
    while(!ans[limit] && limit >= 1) --limit;
    for(int i = limit; i >= 0; --i) printf("%d", ans[i]);
} 