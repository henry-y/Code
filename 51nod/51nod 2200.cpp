/*
x在前：a[x]*b[x]+a[y]*(b[x]+b[y])
y在前：a[y]*b[y]+a[x]*(b[x]+b[y])
*/
#include <bits/stdc++.h>

const int N = 200010;
int n;
struct Node {
	long long a, b;
} a[N];

bool cmp(Node x, Node y) {
	return y.a * x.b < x.a * y.b;
}

int main() {
	std::cin >> n;
	for(int i = 1; i <= n; ++i) {
		std::cin >> a[i].a >> a[i].b;
		if(!a[i].a || !a[i].b) --i, --n;
	}
	std::sort(a + 1, a + n + 1, cmp);
	long long ans = 0, T = 0;
	for(int i = 1; i <= n; ++i) T += a[i].b, ans += a[i].a * T;
	std::cout << ans << std::endl;
}