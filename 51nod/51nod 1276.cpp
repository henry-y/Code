#include <bits/stdc++.h>
using namespace std;

const int N = 200010;

int a[N], n, m, Ans[N], b[N];
bool vis[N];
struct query {
	int id, v;
}q[N];
vector<int>v[N];

bool cmp(query a, query b) { return a.v < b.v; }

int main() {
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		b[i] = a[i];
	}
	int cnt = n;
	for(int i = 1; i <= m; ++i) { 
		scanf("%d", &q[i].v); 
		q[i].id = i; 
		b[++cnt] = q[i].v;
	}
	sort(b + 1, b + cnt + 1);
	for(int i = 1; i <= n; ++i) {
		a[i] = lower_bound(b + 1, b + cnt + 1, a[i]) - b;
		v[a[i]].push_back(i);
	} 
	for(int i = 1; i <= m; ++i) {
		q[i].v = lower_bound(b + 1, b + cnt + 1, q[i].v) - b;
	}
	vis[0] = vis[n + 1] = 1;
	sort(q + 1, q + m + 1, cmp);

	int now = 0, ans = 1;
	for(int i = 1; i <= m; ++i) {
		while(now <= q[i].v) {
			for(int i = 0, len = v[now].size(); i < len; ++i) {
				if(!vis[v[now][i] - 1] && !vis[v[now][i] + 1]) ++ans;
				vis[v[now][i]] = 1;
				if(vis[v[now][i] - 1] && vis[v[now][i] + 1]) --ans;
			}
			++now;
		}
		Ans[q[i].id] = ans;
	}
	for(int i = 1; i <= m; ++i) printf("%d\n", Ans[i]);
}