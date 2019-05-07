#include <cstdio>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;
#define ll long long

ll n, f[100];
map<ll, ll> dp[100];

ll dfs(int now, ll leave) {
	if(leave == 0) return 1;
	if(!now) return 0;
	if(dp[now].find(leave) != dp[now].end()) return dp[now][leave];
	ll res = 0;
	if(leave < f[now + 1]) res += dfs(now - 1, leave);
	if(leave >= f[now]) res += dfs(now - 1, leave - f[now]);
	return dp[now][leave] = res;
}

int main() {
	scanf("%lld", &n);
	f[1] = 1; f[2] = 2;
	int i = 3;
	for(; (f[i] = f[i - 1] + f[i - 2]) <= n; ++i); 
	printf("%lld\n", dfs(i - 1, n));
}