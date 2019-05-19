#include <cstdio>
#include <algorithm>

const int N = 200010;

char s[N];
int n, top, ans[N], st[N], id[N][3], cur, dep;

int main() {
	bool flag = 0;
	scanf("%d%s", &n, s + 1);
	for(int i = 1; i <= n; ++i) {
		if(s[i] == '(') st[++top] = i, dep++;
		else {
			id[++cur][0] = i;
			id[cur][1] = st[top--];
			id[cur][2] = dep & 1;
			--dep;
		}
		if(!top) {
			for(int i = 1; i <= cur / 2; ++i) 
				ans[id[i][0]] = ans[id[i][1]] = id[i][2];
			for(int i = cur / 2 + 1; i <= cur; ++i) 
				ans[id[i][0]] = ans[id[i][1]] = id[i][2];
			dep = 0;
		}
	}
	for(int i = 1; i <= n; ++i) printf("%d", ans[i]);
}