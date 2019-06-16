#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

inline void read(int &x) {
	x = 0; int f = 1;
	char c = getchar();
	while(c < '0' || c > '9') {
		if(c == '-') f = -1;
		c = getchar();
	} 
	while(c >= '0' && c <= '9') {
		x = x * 10 + c - '0';
		c = getchar();
	}
	x *= f;
}

#define ll long long
const int N = 100010;

int T, n, m, K, P, a[N];
int d[N], f[N][51];
bool vis[N], in[N][51];

int head[N], cnt;
struct edge {
    int to, nxt, v;
} e[N << 1];

struct Node {
    int id, dis;
    bool operator < (Node x) const {
    	return dis > x.dis;
    }
};
priority_queue<Node> q;

void ins(int u, int v, int w) {
    e[++cnt] = {v, head[u], w};
    head[u] = cnt;
}

void inc(int &a, int b) {a += b; if(a >= P) a -= P;}

void Dijkstra(int s) {
	memset(d, 0x3f, sizeof(d));
    memset(vis, 0, sizeof(vis));
    d[s] = 0;
    q.push({s, 0});

    while(!q.empty()) {
        int u = q.top().id;
        q.pop();
        if(vis[u]) continue;
        vis[u] = 1;

        for(int i = head[u]; i; i = e[i].nxt) {
            int v = e[i].to;
            if(d[v] > d[u] + e[i].v) {
                d[v] = d[u] + e[i].v;
                q.push({v, d[v]});
            }
        }
    }
}

int dfs(int u, int k) {
	if(k < 0) return 0;
    if(in[u][k]) return -1;
    if(f[u][k]) return f[u][k];
    if(u == n) f[u][k] = 1;
    in[u][k] = 1;
    for(int i = head[u]; i; i = e[i].nxt) {
        int v = e[i].to, w = d[v] + e[i].v - d[u];
        if(w <= k) {
            w = dfs(v, k - w);
            if(w == -1) return -1;
            f[u][k] = (f[u][k] + w) % P;
        }
    }
    in[u][k] = 0;
    return f[u][k];
}

int U[N << 1], V[N << 1], W[N << 1];

int main() {
    read(T);
    while(T--) {
        cnt = 0;
        memset(head, 0, sizeof(head));
        memset(f, 0, sizeof(f));
        memset(in, 0, sizeof(in));

        read(n); read(m); read(K); read(P);
        for(int i = 1; i <= m; ++i) {
            read(U[i]), read(V[i]), read(W[i]);
            ins(V[i], U[i], W[i]);
        }
        Dijkstra(n);
        
        cnt = 0;
        memset(head, 0, sizeof(head));
        for(int i = 1; i <= m; ++i) {
        	ins(U[i], V[i], W[i]);
		}

        printf("%d\n", dfs(1, K));
    }
}
