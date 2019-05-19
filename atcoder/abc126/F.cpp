#include <bits/stdc++.h>
using namespace std;

int m, k;

int main() {
	cin >> m >> k;
	int sum = 0;
	for(int i = 0; i < (1 << m); ++i) if(i != k) sum ^= i;
	if(!k) {
		for(int i = 0; i < (1 << m); ++i) printf("%d %d ", i, i);
		puts("");
		return 0;
	}
	if(m == 1) {
		if(k >= 1) puts("-1");
		else puts("0 0 1 1");
		return 0;
	}
	if((1 << m) <= k) return puts("-1"), 0;
	printf("%d ", k);
	for(int i = 0; i < (1 << m); ++i) if(i != k) printf("%d ", i);
	printf("%d ", k);
	for(int i = (1 << m) - 1; i >= 0; --i) if(i != k) printf("%d ", i);
}