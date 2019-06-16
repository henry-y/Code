#include <bits/stdc++.h>
using namespace std;

const int N = 100010;

int n, a[N];
bool vis[N];

int main() {
	scanf("%d", &n);
	int now = 1;
	for(int i = 2; i <= n; ++i) {
		if(!vis[i]) {
			for(int j = i; j <= n; j += i) {
				a[j] = now;
				vis[j] = 1;
			}
			++now;
		}
		printf("%d ", a[i]);
	}
}