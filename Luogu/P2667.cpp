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
#define G getchar

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
const int N = 100010;
const int mod = 1000000009;
const int inf = 0x3f3f3f3f;

/*
两个线段树维护
第一个线段树维护区间和和区间min以及叶节点的id，这个线段树放还有护甲的
每次修改时，区间减，单点查询，然后查询min有没有小于等于0的。有的话就设为inf然后标记一下，放到第二个线段树里。
第二个线段树区间直接减2即可。放进去的时候是单点覆盖。
不膜，在统计的时候才膜，不然没法做
 */

int n, m;
int a[N];
bool vis[N];

struct tree {
    ll mn, sum, tag;
    int id, l, r;
} t[N<<2][2];

#define lc (rt << 1)
#define rc (rt << 1 | 1)

void up(int rt, int op) {
    t[rt][op].mn = min(t[lc][op].mn, t[rc][op].mn);
    t[rt][op].sum = (t[lc][op].sum + t[rc][op].sum);
}

void build(int l, int r, int rt, int op) {
    t[rt][op].l = l; t[rt][op].r = r;
    if(l == r) {
        t[rt][op].sum = t[rt][op].mn = a[l];
        t[rt][op].id = l;
        if(op) t[rt][op].sum = t[rt][op].mn = 0;
        return;
    }
    int mid = (l + r) >> 1;
    build(l, mid, lc, op);
    build(mid + 1, r, rc, op);
    up(rt, op);
}

#define l (t[rt][op].l)
#define r (t[rt][op].r)
#define mid ((l + r) >> 1)

void down(ll ln, ll rn, int rt, int op) {
    if(t[rt][op].tag) {
        ll x = t[rt][op].tag; t[rt][op].tag = 0;
        t[lc][op].mn = (t[lc][op].mn + x); 
        t[rc][op].mn = (t[rc][op].mn + x);
        t[lc][op].sum = (t[lc][op].sum + ln * x); 
        t[rc][op].sum = (t[rc][op].sum + rn * x);
        t[lc][op].tag = (t[lc][op].tag + x); 
        t[rc][op].tag = (t[rc][op].tag + x);
    }
}

void upd(int L, int R, int rt, ll c, int op) {
    if(L <= l && r <= R) {
        t[rt][op].sum += (r - l + 1) * c; t[rt][op].mn += c;
        t[rt][op].tag += c;
        return;
    }
    down(mid - l + 1, r - mid, rt, op);
    if(L <= mid) upd(L, R, lc, c, op);
    if(R > mid) upd(L, R, rc, c, op);
    up(rt, op);
}

void upd_new(int pos, int rt, ll c, int op) {
    if(l == r) {
        t[rt][op].sum = t[rt][op].mn = c;
        return;
    }
    down(mid - l + 1, r - mid, rt, op);
    if(pos <= mid) upd_new(pos, lc, c, op);
    else upd_new(pos, rc, c, op);
    up(rt, op);
}

ll query_sum(int pos, int rt, int op) {
    if(l == r) return t[rt][op].mn;
    down(mid - l + 1, r - mid, rt, op);
    if(pos <= mid) return query_sum(pos, lc, op);
    else return query_sum(pos, rc, op);
}

int query_id(int rt, int op) {
    if(l == r) return t[rt][op].id;
    down(mid - l + 1, r - mid, rt, op);
    if(t[rt][op].mn == t[lc][op].mn) return query_id(lc, op);
    else return query_id(rc, op);
}

#undef lc
#undef rc
#undef l
#undef r
#undef mid

int main() {
    in(n), in(m);
    for(int i = 1; i <= n; ++i) in(a[i]);
    build(1, n, 1, 0); build(1, n, 1, 1);
    
    char s[2];
    int l, r, x;
    ll ans = 0;
    
    for(int i = 1; i <= m; ++i) {
        scanf("%s", s);
        if(s[0] == 'A') {
            in(l), in(r), in(x);
            upd(l, r, 1, -x, 0);
            upd(l, r, 1, -2 * x, 1);
            while(t[1][0].mn <= 0) {
                int id = query_id(1, 0);
                vis[id] = 1;
                ll now = query_sum(id, 1, 0);
                upd_new(id, 1, inf, 0);
                upd_new(id, 1, now, 1);
            }
        } else {
            in(x);
            if(!vis[x]) {
                ans += a[x] - query_sum(x, 1, 0);
                ans %= mod;
            } else {
                ans += a[x] - query_sum(x, 1, 1);
                ans %= mod;
            }
        }
    }
    outn(ans);
}