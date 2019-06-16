#include <bits/stdc++.h>
using namespace std;

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

#define ll long long
const int N = 500010;

int n, m, f[N], siz[N];

int find(int x) {
    if(f[x] == x) return f[x];
    return f[x] = find(f[x]);
}

int main() {
    in(n), in(m);
    for(int i = 1; i <= n; ++i) siz[i] = 1, f[i] = i;
    for(int i = 1; i <= m; ++i) {
        int len; read(len);
        if(!len) continue;
        --len;
        int now; read(now);
        while(len--) {
            int x; read(x);
            now = find(now);
            x = find(x);
            if(x != now) {
                f[x] = now;
                siz[now] += siz[x];
                siz[x] = 0;
            }
        }
    }
    for(int i = 1; i <= n; ++i) out(siz[find(i)]);
    puts("");
    return 0;
}