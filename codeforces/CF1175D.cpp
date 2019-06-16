#include <bits/stdc++.h>

using namespace std;

#define ll long long
const int N = 300010;
ll s[N], a[N];
int n, k;
ll ans = 0;

int main() {
	scanf("%d%d", &n, &k);
	for(int i = 1; i <= n; ++i) {
		scanf("%lld", &a[i]);
		s[i] = s[i - 1] + a[i];
	}
	ans = 1LL * k * s[n];
	sort(s + 1, s + n);
	for(int i = 1; i < k; ++i) ans -= s[i];
	printf("%lld\n", ans);
}