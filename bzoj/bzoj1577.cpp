#include <bits/stdc++.h>
using namespace std;

#define N 200100
int k, n, c, vis[N];
struct Node {int l, r, num;}a[N];
struct MAX {
	int id, ed;
	bool operator < (const MAX &x) const {
		return ed < x.ed;
	}
};
struct MIN {
	int id, ed;
	bool operator < (const MIN &x) const {
		return ed > x.ed;
	}
};
priority_queue<MAX>qmax;
priority_queue<MIN>qmin;

bool cmp(Node a, Node b) {
	return a.l < b.l;
}

int main() {
	scanf("%d%d%d", &k, &n, &c);
	for(int i = 1, l, r, num; i <= k; ++i) {
		scanf("%d%d%d", &l, &r, &num);
		a[i] = (Node) {l, r, num};
	}
	int ans = 0, tot = 0;
	sort(a + 1, a + k + 1, cmp);
	for(int i = 1; i <= k; ++i) {
		qmax.push((MAX){i, a[i].r});
		qmin.push((MIN){i, a[i].r});
		tot += a[i].num;
		if(a[i].l != a[i + 1].l) {
			while(!qmin.empty() && qmin.top().ed <= a[i].l) {
				MIN x = qmin.top(); qmin.pop();
				if(!vis[x.id]) {
					ans += a[x.id].num;
					tot -= a[x.id].num;
					vis[x.id] = 1;
				}
			}
			while(tot > c) {
				MAX x = qmax.top();
				if(!vis[x.id]) {
					if(tot - a[x.id].num > c) {
						tot -= a[x.id].num;
						vis[x.id] = 1;
						qmax.pop();
					} else a[x.id].num -= tot - c, tot = c;
				} else qmax.pop();
			}
		}
	}
	while(!qmax.empty()) {
		MAX x = qmax.top(); qmax.pop();
		if(!vis[x.id]) ans += a[x.id].num;
	}
	printf("%d\n", ans);
}
