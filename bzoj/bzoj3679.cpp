#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll limit = 700001;
const ll base = 1313141;
const double eps = 1e-13;
 
ll l, r, n;
int cnt, digit[20];
map<ll, ll> f[19];
 
ll dfs(int pos, int num, bool lead, bool done, ll mul, ll Hash) {
    if(!pos) {
        if(mul <= n && mul) return 1;
        return 0;
    }
    if(!done && !lead && f[pos].find(mul) != f[pos].end()) return f[pos][mul];
    int ed = done ? digit[pos] : 9;
    ll res = 0;
    for(int i = 0; i <= ed; ++i) {
        if(lead) {
            if(!i) res += dfs(pos - 1, i, lead && (!i), done && (i == ed), mul, Hash * base % limit);
            else res += dfs(pos - 1, i, lead && (!i), done && (i == ed), 1ll * mul * i, (Hash * base % limit + i) % limit);
        } else {
            if(mul * i > n || !i) continue;
            res += dfs(pos - 1, i, lead && (!i), done && (i == ed), 1ll * mul * i, (Hash * base % limit + i) % limit);
        }
    }
    if(done || lead) return res;
    return f[pos][mul] = res;
}
 
ll count(ll x) {
    cnt = 0;
    for(int i = 0; i < 19; ++i) f[i].clear();
    while(x) digit[++cnt] = x % 10ll, x /= 10ll;
    return dfs(cnt, 0, 1, 1, 1ll, 0ll);
}
 
int main() {
    cin >> n >> l >> r;
    cout << (count(r - 1ll) - count(l - 1ll)) << endl;
}