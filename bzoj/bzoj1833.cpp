#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll l, r;
int cnt, digit[20], now;
ll f[20][20];

ll dfs(int pos, int num, bool lead, bool done, int tot) {
	if(!pos) return tot;
	if(!done && (!lead||now) && f[pos][tot] != -1) return f[pos][tot];
	int ed = done ? digit[pos] : 9;
	ll res = 0;
	for(int i = 0; i <= ed; ++i) {
		if(now == 0) {
			if(lead) res += dfs(pos - 1, i, lead && (!i), done && (i == ed), tot);
			else res += dfs(pos - 1, i, lead && (!i), done && (i == ed), tot + (i == now));
		} else {
			res += dfs(pos - 1, i, lead && (!i), done && (i == ed), tot + (i == now));
		}
	}
	if(done || (!now && lead)) return res;
	return f[pos][tot] = res;
}

ll count(ll x) {
	cnt = 0; 
	memset(f, -1, sizeof(f));
	while(x) digit[++cnt] = x % 10ll, x /= 10ll;
	return dfs(cnt, 0, 1, 1, 0);
}

int main() {
	cin >> l >> r;
	for(int i = 0; i <= 9; ++i) {
		now = i;
		if(i) putchar(' ');
		cout << count(r) - count(l - 1);
	}
	puts("");
}