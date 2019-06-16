#include <bits/stdc++.h>
using namespace std;

const int N = 100010;

int n, a[N], cnt[2];

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		cnt[a[i] & 1]++;
	}
	if(cnt[0] && cnt[1]) {
		sort(a + 1, a + n + 1);
		for(int i = 1; i <= n; ++i) printf("%d ", a[i]);
		puts("");
	} else {
		for(int i = 1; i <= n; ++i) printf("%d ", a[i]);
		puts("");
	}
}