#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define N 1000010
int a[N], b[N], n;
ll f[N];

ll calc(int x, int y) {
	if(x == y) return 100000000;
	return abs(x - y);
}

int main() {
	cin >> n;
	for(int i = 1; i <= n; ++i) cin >> a[i] >> b[i];
	sort(a + 1, a + n + 1);
	sort(b + 1, b + n + 1);
	f[1] = calc(a[1], b[1]);
	f[2] = min(f[1] + calc(a[2], b[2]), calc(a[1], b[2]) + calc(b[1], a[2]));
	for(int i = 3; i <= n; ++i) {
		f[i] = f[i - 1] + calc(a[i], b[i]); //i
		f[i] = min(f[i], f[i - 2] + calc(a[i], b[i - 1]) + calc(b[i], a[i - 1])); //i和i-1
		//混搭
		f[i] = min(f[i], f[i - 3] + calc(a[i], b[i - 2]) + calc(a[i - 1], b[i - 1]) + calc(a[i - 2], b[i]));//i和i-2
		f[i] = min(f[i], f[i - 3] + calc(a[i], b[i - 1]) + calc(a[i - 1], b[i - 2]) + calc(a[i - 2], b[i]));
		f[i] = min(f[i], f[i - 3] + calc(a[i], b[i - 2]) + calc(a[i - 1], b[i]) + calc(a[i - 2], b[i - 1]));
	}
	cout << f[n] << endl;
}