#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;

int n, m, f[N];

struct edge {
	int u, v, w;
}e[N << 1];

int find(int x) {
	if(f[x] == x) return x;
	return f[x] = find(f[x]);
}

bool cmp(edge a, edge b) {
	return a.w < b.w;
}

int main() {
	scanf("%d%d", &n, &m);
	int cnt = 0;
	for(int i = 1; i <= m; ++i) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		e[++cnt] = (edge) {a, b, 0};
	}
	for(int i = 1; i <= n; ++i) {
		e[++cnt] = (edge) {n + 1, i, 1};
	}
	++n;
	for(int i = 1; i <= n; ++i) f[i] = i;
	int ans = 0;
	sort(e + 1, e + cnt + 1, cmp);
	for(int i = 1; i <= cnt; ++i) {
		int x = find(e[i].u), y = find(e[i].v);
		if(x != y) {
			ans += e[i].w;
			f[y] = x;
		}
	}
	printf("%d\n", ans);
}