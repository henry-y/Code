#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int N = 50010;
const int inf = 0x3f3f3f3f;

ll sum;
int n, m, in[N], root;
int cnt, head[N];
struct edge {
    int to, nxt, v;
} e[N << 1];

void ins(int u, int v, int w) {
    e[++cnt] = (edge) {v, head[u], w};
    head[u] = cnt;
}

namespace Sub1 {
int a[N], tot, ans = inf;
void solve() {
    for(int i = head[1]; i; i = e[i].nxt) {
        a[++tot] = e[i].v;
    }
    sort(a + 1, a + tot + 1);
    reverse(a + 1, a + tot + 1);
    for(int i = 1, j = 2 * m; m; i++, j--, m--) {
        ans = min(ans, a[i] + a[j]);
    }
    printf("%d\n", ans);
}
}

namespace Sub2 {
int q[N], vis[N], f[N], ans = 0;
void bfs(int s) {
    int l = 1, r = 2;
    q[l] = s;
    memset(f, 0x3f, sizeof(f));
    memset(vis, 0, sizeof(vis));
    f[s] = 0;
    while(l < r) {
        int u = q[l++];
        if(vis[u]) continue;
        vis[u] = 1;
        for(int i = head[u]; i; i = e[i].nxt) {
            int v = e[i].to;
            if(f[v] > f[u] + e[i].v) {
                f[v] = f[u] + e[i].v;
                q[r++] = v;
            }
        }
    }
}
void solve() {
    bfs(1);
    int root = 0; f[0] = 0;
    for(int i = 1; i <= n; ++i) if(f[i] > f[root]) root = i;
    bfs(root);
    for(int i = 1; i <= n; ++i) if(f[i] > ans) ans = f[i];
    printf("%d\n", ans);
} 
}

namespace Sub4 {
int a[N], tot;
void dfs(int u, int pre) { 
    for(int i = head[u]; i; i = e[i].nxt) {
        int v = e[i].to;
        if(v == pre) continue;
        a[++tot] = e[i].v;
        dfs(v, u);
    }
}
bool check(int x) {
    int sum = 0, num = 0;
    for(int i = 1; i < n; ++i) {
        sum += a[i];
        if(sum >= x) sum = 0, ++num;
    }
    if(num >= m) return 1;
    return 0;
}
void solve() {
    int id = 0;
    for(int i = 1; i <= n; ++i) if(in[i] & 1) id = i;
    dfs(id, id);
    int l = 0, r = 10000LL * n, ans = 0;
    while(l <= r) {
        int mid = (l + r) >> 1;
        if(check(mid)) l = mid + 1, ans = mid;
        else r = mid - 1;
    }
    printf("%d\n", ans);
}
}

namespace Sub3 {
int Sum, g[N], tot, a[N];
int Limit = 0;
void dfs(int u, int fa) {
    tot = 0;
    multiset<int>s;
    for(int i = head[u]; i; i = e[i].nxt) {
        int v = e[i].to;
        if(v == fa) continue;
        dfs(v, u);
        if(g[v] + e[i].v >= Limit) ++Sum;
        else s.insert(g[v] + e[i].v);
    }
    while(!s.empty()) {
        if(s.size() == 1) {
            g[u] = max(g[u], *s.begin());
            break;
        }
        multiset<int>::iterator it = s.lower_bound(Limit - *s.begin());
        if(it == s.begin() && s.count(*it) == 1) ++it;
        if(it == s.end()) g[u] = max(g[u], *s.begin()), s.erase(s.begin());
        else {
            ++Sum;
            s.erase(it);
            s.erase(s.begin());
        }
    }
} 
bool check(ll x, int root) {
    memset(g, 0, sizeof(g));
    Limit = x; Sum = 0;
    dfs(root, root);
    if(Sum >= m) return 1;
    return 0;
}
void solve(int root) {
    ll l = 1, r = sum, ans = 0;
    while(l <= r) {
        ll mid = (l + r) >> 1;
        if(check(mid, root)) l = mid + 1, ans = mid;
        else r = mid - 1;
    }
    printf("%lld\n", ans);
}
}

int main() {
    scanf("%d%d", &n, &m);
    bool flag1 = 1, flag2 = 1;
    for(int i = 1; i < n; ++i) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        ins(u, v, w); ins(v, u, w);
        if(u != 1) flag1 = 0;
        if(v != u + 1) flag2 = 0;
        in[u]++; in[v]++;
        sum += w;
    }
    if(flag1) {Sub1::solve(); return 0;}
    if(flag2) {Sub4::solve(); return 0;}
    if(m == 1) {Sub2::solve(); return 0;}
    Sub3::solve(1); 
    return 0;
}