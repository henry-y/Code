#include <bits/stdc++.h>
using namespace std;

const int N = 100010;
int n, m, f[N][31], lg[N];

int query(int l, int r) {
	int k = lg[r - l + 1];
	return max(f[l][k], f[r - (1 << k) + 1][k]);
}

int main() {
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i) scanf("%d", &f[i][0]);
	for(int i = 2; i <= n; ++i) lg[i] = lg[i / 2] + 1;

	for(int j = 1; j <= 30; ++j) 
		for(int i = 1; i + (1 << j) - 1 <= n; ++i) 
			f[i][j] = max(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);

	for(int i = 1; i <= m; ++i) {
		int l, r;
		scanf("%d%d", &l, &r);
		printf("%d\n", query(l, r));
	}
}