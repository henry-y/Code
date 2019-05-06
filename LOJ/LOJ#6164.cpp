#include <bits/stdc++.h>
using namespace std;

#define N 50010
#define ll long long

int cnt[N], sum, c[N], cnt1[N];
int n, m, a[N], ans[N], tot;

int bn[310][N], b[310];
int d[N][30];
bool vis[N];

struct Qu {
	int l, r, k, id;
}q[N];

int block;
bool cmp(Qu a, Qu b) {
	return a.l / block == b.l / block ? a.r < b.r : a.l / block < b.l / block;
}

void add(int x) {
	if(cnt1[a[x]] >= block) return;
	c[cnt[a[x]]]--;
	cnt[a[x]]++;
	c[cnt[a[x]]]++;
}

void Del(int x) {
	if(cnt1[a[x]] >= block) return;
	c[cnt[a[x]]]--;
	cnt[a[x]]--;
	c[cnt[a[x]]]++;
}

void init() {
	for(int i = 2; i <= n; ++i) {
		if(!vis[i]) {
			for(int j = i; j <= n; j += i) {
				d[j][0]++;
				d[j][d[j][0]] = i;
				vis[j] = 1;
			}
		}
	}
	memset(vis, 0, sizeof(vis));
}

bool check(int x) {
	if(!x) return 0;
	for(int i = 1; i <= d[x][0]; ++i) {
		if(vis[d[x][i]]) return 0;
	}
	return 1;
}

int main() {

	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i) scanf("%d", &a[i]);
	for(int i = 1; i <= m; ++i) {
		scanf("%d%d%d", &q[i].l, &q[i].r, &q[i].k);
		q[i].id = i;
	}
	
	init();

	block = sqrt(n);
	sort(q + 1, q + m + 1, cmp);

	for(int i = 1; i <= n; ++i) {
		cnt1[a[i]]++;
		if(cnt1[a[i]] == block) {
			b[++tot] = a[i];
		}
	}
	for(int i = 1; i <= tot; ++i) {
		for(int j = 1; j <= n; ++j) {
			bn[i][j] = bn[i][j - 1] + (a[j] == b[i]);
		}
	}

	int l = q[1].l, r = q[1].l - 1;
	for(int i = 1; i <= m; ++i) {

		int ql = q[i].l, qr = q[i].r;
		while(l > ql) add(--l);
		while(l < ql) Del(l++);
		while(r < qr) add(++r);
		while(r > qr) Del(r--);
		
		sum = 0;
		for(int j = 1; j <= d[q[i].k][0]; ++j) vis[d[q[i].k][j]] = 1;

		for(int j = 1; j < block; ++j) {
			if(check(j)) sum += c[j]; 
		}
		for(int j = 1; j <= tot; ++j) {
			if(check(bn[j][r] - bn[j][l - 1])) sum++;
		}

		ans[q[i].id] = sum;
		for(int j = 1; j <= d[q[i].k][0]; ++j) vis[d[q[i].k][j]] = 0;
	}
	
	for(int i = 1; i <= m; ++i) printf("%d\n", ans[i]);

	return 0;

}