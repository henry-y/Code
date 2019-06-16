#include <bits/stdc++.h>
using namespace std;

const int N = 2010;

int n, a[N];

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= 2 * n; ++i) scanf("%d", &a[i]);
	sort(a + 1, a + 2 * n + 1);
	bool flag = 1;
	for(int i = 1; i < 2 * n; ++i) {
		if(a[i] != a[i + 1]) flag = 0;
	}
	if(flag) puts("-1");
	else {
		for(int i = 1; i <= n; ++i) printf("%d ", a[i]);
		for(int i = n + 1; i <= 2 * n; ++i) printf("%d ", a[i]);
	}
}