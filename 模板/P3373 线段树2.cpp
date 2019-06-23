#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int N = 100010;

int n, m, P;
int a[N];
struct tree {
	int l, r;
	ll mul, add, sum;
} t[N << 2];

template<class A, class B>void inc(A &a, B b) {a += b; if(a >= P) a %= P;}
template<class A, class B>void Mul(A &a, B b) {a *= b; if(a >= P) a %= P;}

#define lc (rt << 1)
#define rc (rt << 1 | 1)

void up(int rt) {t[rt].sum = (t[lc].sum + t[rc].sum) % P;}

void build(int l, int r, int rt) {
	t[rt].l = l; t[rt].r = r;
	t[rt].mul = 1, t[rt].add = 0;
	if(l == r) {t[rt].sum = a[l] % P; return;}
	int mid = (l + r) >> 1;
	build(l, mid, lc), build(mid + 1, r, rc);
	up(rt);
}

#define mid ((l + r) >> 1)
#define l (t[rt].l)
#define r (t[rt].r)

void down(int ln, int rn, int rt) {
    if(t[rt].mul != 1) {
        Mul(t[lc].mul, t[rt].mul); Mul(t[rc].mul, t[rt].mul);
        Mul(t[lc].sum, t[rt].mul); Mul(t[rc].sum, t[rt].mul);
        Mul(t[lc].add, t[rt].mul); Mul(t[rc].add, t[rt].mul);
        t[rt].mul = 1;
    }
    if(t[rt].add) {
        inc(t[lc].add, t[rt].add); inc(t[rc].add, t[rt].add);
        inc(t[lc].sum, t[rt].add * ln); inc(t[rc].sum, t[rt].add * rn);
        t[rt].add = 0;
    }
}

void upd_mul(int L, int R, int rt, ll c) {
	if(L <= l && r <= R) {
		Mul(t[rt].sum, c); Mul(t[rt].mul, c); Mul(t[rt].add, c);
		return;
	}
	down(mid - l + 1, r - mid, rt);
	if(L <= mid) upd_mul(L, R, lc, c);
	if(R > mid) upd_mul(L, R, rc, c);
	up(rt);
}

void upd_add(int L, int R, int rt, ll c) {
	if(L <= l && r <= R) {
		inc(t[rt].sum, 1ll * (r - l + 1) * c); 
		inc(t[rt].add, c);
		return;
	}
	down(mid - l + 1, r - mid, rt);
	if(L <= mid) upd_add(L, R, lc, c);
	if(R > mid) upd_add(L, R, rc, c);
	up(rt);
}

ll query(int L, int R, int rt) {
	if(L <= l && r <= R) return t[rt].sum;
	ll ans = 0;
	down(mid - l + 1, r - mid, rt);
	if(L <= mid) inc(ans, query(L, R, lc));
	if(R > mid) inc(ans, query(L, R, rc));
	return ans;
}

#undef lc
#undef rc
#undef mid
#undef l
#undef r

int main() {
	scanf("%d%d%d", &n, &m, &P);
	for(int i = 1; i <= n; ++i) scanf("%d", &a[i]);
	build(1, n, 1);
	for(int i = 1; i <= m; ++i) {
		int type, x, y; ll k;
		scanf("%d%d%d", &type, &x, &y);
		if(type == 1) {
			scanf("%lld", &k);
			upd_mul(x, y, 1, k);
		}
		if(type == 2) {
			scanf("%lld", &k);
			upd_add(x, y, 1, k);
		}
		if(type == 3) {
			printf("%lld\n", query(x, y, 1));
		}
	}
	return 0;
}