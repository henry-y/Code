#include <cstdio>
#include <algorithm>
using namespace std;

pair<int, int> ans[10];
int n, cnt;

int query(int l1, int r1, int l2, int r2) {
	printf("? %d %d %d %d\n", l1, r1, l2, r2);
	fflush(stdout);
	int num;
	scanf("%d", &num);
	return num;
}

int solve1(int cur) {
	int l = 1, r = n;
	while(l < r) {
		int mid = (l + r) >> 1;
		if(query(cur, l, cur, mid) & 1) r = mid;
		else l = mid + 1;
	}
	return l;
}

int solve2(int cur) {
	int l = 1, r = n;
	while(l < r) {
		int mid = (l + r) >> 1;
		if(query(l, cur, mid, cur) & 1) r = mid;
		else l = mid + 1;
	}
	return l;
}

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) {
		int tot = query(i, 1, i, n);
		if(tot & 1) ans[++cnt] = make_pair(i, solve1(i));
	}
	if(!cnt) {
		for(int i = 1; i <= n; ++i) {
			int tot = query(1, i, n, i);
			if(tot & 1) {
				if(!cnt) ans[++cnt] = make_pair(solve2(i), i);
				else ans[++cnt] = make_pair(ans[1].first, i);
			}
		}
	}
	printf("! %d %d %d %d\n", ans[1].first, ans[1].second, ans[2].first, ans[2].second);
	fflush(stdout);
}