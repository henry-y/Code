#include <bits/stdc++.h>
using namespace std;

const int N = 200010;

int n, m, f[N];
int ans = 0;

int find(int x) {
	if(f[x] == x) return x;
	return f[x] = find(f[x]);
}

int main() {
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i) f[i] = i;
	for(int i = 1; i <= m; ++i) {
		int x, y; scanf("%d%d", &x, &y);
		x = find(x), y = find(y);
		if(x == y) continue;
		else f[x] = y, ++ans;
	}
	printf("%d\n", ans);
}