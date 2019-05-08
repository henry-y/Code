#include <bits/stdc++.h>

using namespace std;
#define ll long long

ll a, b, now;
int cnt = 0, vis[100];

int main() {
	cin >> a >> b;
	int ans = 0; 
	for(ll i = 0; i <= 62; ++i) {
		if((a >> i) & 1ll) ++ans, vis[i] = 1, now += 1ll << i;
	}
	for(ll i = 0; i <= 62; ++i) {
		if(!vis[i]) {
			if(a + (1ll << i) <= b) {
				a += (1ll << i);
				++ans;
			}
		}
	}
	cout << ans << endl;
}