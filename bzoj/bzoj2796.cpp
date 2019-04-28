#include <bits/stdc++.h>
using namespace std;
#define ll long long
int T;
ll n, f[100];

int main() {
	f[1] = f[2] = 1;
	for(int i = 3; i <= 90; ++i) f[i] = f[i - 1] + f[i - 2];
	cin >> T;
	while(T--) {
		cin >> n;
		ll mn = 1e18;
		int ans = 0;
		while(n) {
			for(int i = 1; i <= 90; ++i) {
				mn = min(mn, abs(f[i] - n));
			}
			n = mn;
			++ans;
		}
		cout << ans << endl;
	}
}