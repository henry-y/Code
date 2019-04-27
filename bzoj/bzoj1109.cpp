#include <bits/stdc++.h>
using namespace std;

#define N 100010
int n, c[N], tot;
struct task {
	int v1, v2;
}a[N];

namespace BIT {
#define lowbit(i) (i&-i)
void add(int x, int v) {
	for(int i = x; i <= n; i += lowbit(i)) c[i] = max(c[i], v);
}
int query(int x) {
	int ans = 0;
	for(int i = x; i; i -= lowbit(i)) ans = max(ans, c[i]);
	return ans;
}
}
using namespace BIT;

bool operator < (task a, task b) {
	if(a.v1 != b.v1) return a.v1 < b.v1;
	return a.v2 < b.v2;
}

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) {
		int x;
		scanf("%d", &x);
		if(i < x) continue;
		a[++tot] = (task) {i - x, x};
	}
	int ans = 0;
	sort(a + 1, a + tot + 1);
	for(int i = 1; i <= tot; ++i) {
		int tmp = query(a[i].v2 - 1) + 1;
		ans = max(ans, tmp);
		add(a[i].v2, tmp);
	}
	printf("%d\n", ans);
}

/*
最后的序列(去掉凑数的)S单调递增。i单调递增，a_i单调递增，i-a_i单调不减
i-a_i单调不减且a_i单调递增的话，那么按照i-a_i排序，对a_i做LIS
 */