#include <bits/stdc++.h>

#define ll long long
#define inf 0x3f3f3f3f
#define il inline

namespace io {

    #define in(a) a=read()
    #define out(a) write(a)
    #define outn(a) out(a),putchar('\n')

    #define I_int long long
    inline I_int read() {
        I_int x = 0 , f = 1 ; char c = getchar() ;
        while( c < '0' || c > '9' ) { if( c == '-' ) f = -1 ; c = getchar() ; }
        while( c >= '0' && c <= '9' ) { x = x * 10 + c - '0' ; c = getchar() ; }
        return x * f ;
    }
    char F[ 200 ] ;
    inline void write( I_int x ) {
        if( x == 0 ) { putchar( '0' ) ; return ; }
        I_int tmp = x > 0 ? x : -x ;
        if( x < 0 ) putchar( '-' ) ;
        int cnt = 0 ;
        while( tmp > 0 ) {
            F[ cnt ++ ] = tmp % 10 + '0' ;
            tmp /= 10 ;
        }
        while( cnt > 0 ) putchar( F[ -- cnt ] ) ;
    }
    #undef I_int

}
using namespace io ;

using namespace std ;

#define N 100010

int n, m;
int top[N], fa[N], dep[N], siz[N], id[N], a[N];
int tim;

struct Tree {
    int l, r, sum;
}t[N<<2];

int head[N], cnt;
struct edge {
    int to, nxt;
}e[N<<1]; 

void ins(int u, int v) {
    e[++cnt] = (edge) {v, head[u]};
    head[u] = cnt;
}

void dfs1(int u) {
    siz[u] = 1;
    for(int i = head[u]; i; i = e[i].nxt) {
        int v = e[i].to;
        if(v == fa[u]) continue;
        fa[v] = u;
        dep[v] = dep[u] + 1;
        dfs1(v);
        siz[u] += siz[v];
    }
}

void dfs2(int u, int topf) {
    top[u] = topf;
    id[u] = ++tim;
    a[tim] = u;
    int k = 0;
    for(int i = head[u]; i; i = e[i].nxt) {
        int v = e[i].to;
        if(v == fa[u]) continue;
        if(siz[v] > siz[k]) k = v;
    }
    if(!k) return;
    dfs2(k, topf);
    for(int i = head[u]; i; i = e[i].nxt) {
        int v = e[i].to;
        if(v == fa[u] || v == k) continue;
        dfs2(v, v);
    }
}

#define lc (rt << 1)
#define rc (rt << 1 | 1)

void build(int l, int r, int rt) {
    t[rt].l = l; t[rt].r = r;
    int mid = (l + r) >> 1;
    if(l == r) return;
    build(l, mid, lc);
    build(mid + 1, r, rc);
}

#define l (t[rt].l)
#define r (t[rt].r)

void up(int rt) {
    t[rt].sum = t[lc].sum + t[rc].sum;
}

void upd(int pos, int rt) {
    if(l == r) {
        t[rt].sum = 1;
        return;
    }
    int mid = (l + r) >> 1;
    if(pos <= mid) upd(pos, lc);
    else upd(pos, rc);
    up(rt);
}

int query(int L, int R, int rt) {
    if(L <= l && r <= R) return t[rt].sum;
    int res = 0, mid = (l + r) >> 1;
    if(L <= mid) res += query(L, R, lc);
    if(R > mid) res += query(L, R, rc);
    return res;
}

#undef lc
#undef rc
#undef l
#undef r

int solve(int x) {
    while(top[x] != 1) {
//		printf("%d %d %d\n", x, top[x], fa[top[x]]);
        int sum = query(id[top[x]], id[x], 1);
        if(sum) {
            int l = id[top[x]], r = id[x];
            while(l + 1 < r) {
                int mid = (l + r) >> 1;
                sum = query(mid + 1, r, 1);
                if(sum) l = mid + 1;
                else r = mid;
            }
            if(query(r, r, 1)) return a[r];
            return a[l];
        }
        x = fa[top[x]];
    }
    int l = 1, r = id[x], sum = 0;
    while(l + 1 < r) {
        int mid = (l + r) >> 1;
        sum = query(mid + 1, r, 1);
        if(sum) l = mid + 1;
        else r = mid;
    }
    if(query(r, r, 1)) return a[r];
    return a[l];
}

int main() {
    in(n); in(m);
    for(int i = 1, u, v; i < n; ++i) {
        in(u), in(v);
        ins(u, v), ins(v, u);
    }
    
    dfs1(1);
    dfs2(1, 1);
    build(1, n, 1);
    upd(id[1], 1);
    
    for(int i = 1; i <= m; ++i) {
        char op[2];
        int x;
        scanf("%s", op);
        in(x);
        if(op[0] == 'C') upd(id[x], 1);
        else printf("%d\n", solve(x));
    }
    
    return 0;
}