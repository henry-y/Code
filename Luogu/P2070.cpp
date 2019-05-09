#include <bits/stdc++.h>

using namespace std;
#define N 100010
#define ll long long

int n, cnt;
struct task {
    ll l, r;
}a[N];

bool operator < (task a, task b) {
    if(a.l == b.l) return a.r < b.r;
    return a.l < b.l;
}

int main() {
    scanf("%d", &n);
    ll cur = 0; 
    for(int i = 1; i <= n; ++i) {
        char ch[2]; ll x;
        scanf("%lld%s", &x, ch);
        if(ch[0] == 'R') {
            a[++cnt].l = cur;
            a[cnt].r = (cur += x);
        } else {
            a[++cnt].r = cur;
            a[cnt].l = (cur -= x);
        }
//		printf("%d ", cur);
//		printf("%d %d\n", a[i].l, a[i].r);
        if(a[i].l > a[i].r) swap(a[i].l, a[i].r);
    }
//	puts("");

    sort(a + 1, a + cnt + 1);
    ll l = -2000000000, r = a[1].r; 
    ll ans = 0;
    for(int i = 2; i <= n; ++i) {
        if(r >= a[i].l) {
            if(min(a[i].r, r) - max(a[i].l, l) > 0) {
                ans += min(a[i].r, r) - max(a[i].l, l);
                l = min(a[i].r, r);
            }	
        }
        r = max(r, a[i].r);
    }
    printf("%lld\n", ans);
}