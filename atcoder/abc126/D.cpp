#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
#define ll long long

struct edge {
	int to, nxt;
	ll v;
}e[N<<1];
int head[N], cnt, n;

void ins(int u, int v, ll w) {
	e[++cnt] = (edge) {v, head[u], w};
	head[u] = cnt;
}

int ans[N];

void dfs(int u, int fa) {
	for(int i = head[u]; i; i = e[i].nxt) {
		int v = e[i].to;
		if(v == fa) continue;
		if(e[i].v % 2) ans[v] = ans[u] ^ 1;
		else ans[v] = ans[u];
		dfs(v, u);
	}
}

int main() {
	scanf("%d", &n);
	for(int i = 1; i < n; ++i) {
		int u, v; ll w;
		scanf("%d%d%lld", &u, &v, &w);
		ins(u, v, w); ins(v, u, w);
	}
	dfs(1, 0);
	for(int i = 1; i <= n; ++i) printf("%d\n", ans[i]);
}