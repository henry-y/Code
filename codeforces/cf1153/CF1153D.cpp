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

#define I int
inline I read() {
    I x = 0, f = 1; char c = G();
    while(c < '0' || c > '9') {if(c == '-') f = -1; c = G(); }
    while(c >= '0' && c <= '9') {x = x * 10 + c - '0'; c = G(); }
    return x * f;
}

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
#undef I

#define in(x) x = read()
#define outn(x) write(x), putchar('\n')
#define out(x) write(x), putchar(' ')

} using namespace io;

#define ll long long
const int N = 300010;
const int inf = 0x3f3f3f3f;

int n, a[N], fa[N];
int f[N], tot;

int cnt, head[N];
struct edge {
    int to, nxt;
} e[N<<1];

void ins(int u, int v) {
    e[++cnt] = {v, head[u]};
    head[u] = cnt;
}

void dfs(int u) {
    if(a[u]) f[u] = inf;
    bool flag = 0;
    for(int i = head[u]; i; i = e[i].nxt) {
        int v = e[i].to;
        if(v == fa[u]) continue;
        flag = 1;
        dfs(v);
        if(a[u]) f[u] = min(f[u], f[v]);
        else f[u] += f[v];
    }
    if(!flag) f[u] = 1, ++tot;
}

int main() {
    in(n);
    for(int i = 1; i <= n; ++i) in(a[i]);
    for(int i = 2; i <= n; ++i) {
        in(fa[i]);
        ins(i, fa[i]);
        ins(fa[i], i);
    } 
    dfs(1);
//    outn(tot);
    outn(tot - f[1] + 1);
//    for(int i = 1; i <= n; ++i) printf("%d : %d\n", i, f[i]);
}