#include <bits/stdc++.h>
using namespace std;

const int N = 500010;

int n, ans[N], x, cnt;
bool vis[N];

int main() {
	scanf("%d%d", &n, &x);
	vis[0] = vis[x] = 1;
	for(int i = 1; i < (1 << n); ++i) {
		if(!vis[i]) {
			vis[i ^ x] = 1;
			ans[++cnt] = i;
		}
	}
	printf("%d\n", cnt);
	for(int i = 1; i <= cnt; ++i) {
		printf("%d ", ans[i] ^ ans[i - 1]);
	}
	puts("");
}