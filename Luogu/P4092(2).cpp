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

int n = read(), m = read();

int head[N], cnt;
struct edge {
    int to, nxt;
}e[N<<1];

int a[N], f[N], fa[N];
int op[N], c[N];
int ans[N], tot;

void ins(int u, int v) {
    e[++cnt] = (edge) {v, head[u]};
    head[u] = cnt;
}

void dfs(int u) {
    if(a[u]) f[u] = u;
    for(int i = head[u]; i; i = e[i].nxt) {
        int v = e[i].to;
        if(v == fa[u]) continue;
        if(!a[v]) f[v] = u;
        fa[v] = u;
        dfs(v);
    }
}

int find(int u) {
    if(f[u] == u) return u;
    return f[u] = find(f[u]);
}

int main() {
    for(int i = 1; i < n; ++i) {
        int u = read(), v = read();
        ins(u, v), ins(v, u);
    }
    char s[2];
    a[1] = 1;
    for(int i = 1; i <= m; ++i) {
        scanf("%s", s);
        in(c[i]);
        op[i] = s[0] == 'C';
        if(s[0] == 'C') ++a[c[i]];
    }
    dfs(1);
    for(int i = 1; i <= n; ++i) f[i] = find(f[i]);
    for(int i = m; i; --i) {
        if(op[i]) {
            --a[c[i]];
            if(!a[c[i]]) f[c[i]] = fa[c[i]];
        } else {
            ans[++tot] = find(f[c[i]]);
        }
    }
    reverse(ans + 1, ans + tot + 1);
    for(int i = 1; i <= tot; ++i) printf("%d\n", ans[i]);
}