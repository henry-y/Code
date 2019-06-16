#include <bits/stdc++.h>
using namespace std;

const int N = 10010;
int h, n;
int d[N], a[N], b[N];
int cnt, head[N];
bool vis[N];
struct edge {
	int to, nxt;
} e[10000100];
struct Node {
	int id, dis;
};
bool operator < (Node a, Node b) {
	return a.dis > b.dis;
}
priority_queue<Node> q;

void ins(int u, int v) {
	e[++cnt] = {v, head[u]};
	head[u] = cnt;
}

double dis(int x, int y) {
	return (double)sqrt((a[x] - a[y]) * (a[x] - a[y]) + (b[x] - b[y]) * (b[x] - b[y]));
}

void Dijkstra() {
	memset(d, 0x3f, sizeof(d));
	q.push({0, 0});
	d[0] = 0;

	while(!q.empty()) {
		int u = q.top().id;
		q.pop();
		if(vis[u]) continue;
		vis[u] = 1;
		for(int i = head[u]; ~i; i = e[i].nxt) {
			int v = e[i].to;
			if(d[v] > d[u] + 1) {
				d[v] = d[u] + 1;
				q.push({v, d[v]});
			}
		}
	}

	printf("%d\n", d[n + 1] - 1);
}

int main() {
	memset(head, -1, sizeof(head));
	scanf("%d%d", &h, &n);
	for(int i = 1; i <= n; ++i) {
		scanf("%d%d", &a[i], &b[i]);
	}
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= n; ++j) {
			if(i == j) continue;
			if(dis(i, j) <= 1000.0) ins(i, j), ins(j, i);
		}
		if(b[i] <= 1000) ins(0, i), ins(i, 0);
		if(h - b[i] <= 1000) ins(n + 1, i), ins(i, n + 1);
	}
	Dijkstra();
}