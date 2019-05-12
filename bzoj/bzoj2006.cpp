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
const int N = 500010;
const int inf = 1e9;
 
int n = read(), k = read(), L = read(), R = read();
ll s[N];
int a[N], lg[N];
 
struct node {
    ll v;
    int id;
}f[N][21];
 
struct task {
    int id, l, r;
};
 
node query(int l, int r) {
    int K = lg[r - l + 1];
    if(f[l][K].v > f[r - (1 << K) + 1][K].v) return f[r - (1 << K) + 1][K];
    return f[l][K];
}
 
bool operator < (task a, task b) {
    node v1 = query(a.l, a.r), v2 = query(b.l, b.r);
    return s[a.id] - v1.v < s[b.id] - v2.v;
}
 
priority_queue<task>q;
 
void init() {
    for(int i = 1; i <= n; ++i) {
        in(a[i]);
        s[i] = s[i - 1] + a[i];
        f[i][0].v = s[i];
        f[i][0].id = i;
    }
    for(int i = 2; i <= n; ++i) lg[i] = lg[i / 2] + 1;
    for(int j = 1; (1 << j) <= n; ++j) {
        for(int i = 0; i <= n; ++i) {
            if(i + (1 << j) - 1 > n) break;
            if(f[i][j - 1].v > f[i + (1 << (j - 1))][j - 1].v) f[i][j] = f[i + (1 << (j - 1))][j - 1];
            else f[i][j] = f[i][j - 1];
        }
    }
    for(int i = L; i <= n; ++i) {
        q.push({i, max(i - R, 0), i - L});
    }
}
 
int main() {
    init();
 
    ll ans = 0;
    while(k--) {
        task now = q.top(); q.pop();
        node x = query(now.l, now.r);
        ans += s[now.id] - s[x.id];
        if(now.l != x.id) q.push({now.id, now.l, x.id - 1});
        if(x.id != now.r) q.push({now.id, x.id + 1, now.r});
    }
 
    printf("%lld\n", ans);
}