#include <bits/stdc++.h>
using namespace std;

/*
对于ERR
用栈来存放。然后用个vis来判断字母重复。
输入用getline来输入会方便一点
然后对于并列，在栈空的时候进入新循环即可
对于嵌套，注意是否能展开。在嵌套层数的时候需要注意是否有展开（这个只能特判一下，类似栈)
 */

const int inf = 10000;

int T, n, tim, now;
string s[1000], O;

int st[20200][5], vis[26], top;
int idx(char c) {
	return c - 'a';
}

int main() {
	cin >> T;
	while (T--) {

		// Input		
		cin >> n; 
		cin >> O; getchar();
		now = tim = 0;
		if ((int)O.size() == 4) tim = 0;
		else {
			for (int i = 4; i < (int)O.size() - 1; ++i) tim = tim * 10 + O[i] - '0';
		}

		// 清数据
		top = 0;
		memset(vis, 0, sizeof(vis));
		
		bool ERR_flag = 0;
		int tot_not = 0, fzd = 0, mx = 0;

		for (int pos = 1; pos <= n; pos++) {
			getline(cin, s[pos]);

			// 循环类型
			if (s[pos][0] == 'F') { // F

				// 处理循环
				int num1 = 0, num2 = 0, cur = 0;			
				if (s[pos][4] == 'n') num1 = inf, cur = 5;
				else {
					cur = 4;
					while (s[pos][cur] >= '0' && s[pos][cur] <= '9') {
						num1 = num1 * 10 + s[pos][cur] - '0';
						cur++;
					}
				}
				++cur;
				if(s[pos][cur] == 'n') num2 = inf;
				else {
					while (s[pos][cur] >= '0' && s[pos][cur] <= '9') {
						num2 = num2 * 10 + s[pos][cur] - '0';
						cur++;
					}
				}

				// 判断该层复杂度
				if (num1 == num2 || (num1 != inf && num2 != inf)) fzd *= 1;
				if (num1 > num2) tot_not++;
				if (num1 != num2 && num2 == inf && !tot_not) ++fzd; 
				mx = max(mx, fzd);

				// 处理变量
				if (vis[idx(s[pos][2])]) ERR_flag |= 1;
				vis[idx(s[pos][2])] = 1;
				st[++top][0] = idx(s[pos][2]);
				st[top][1] = num1 != num2 && num2 == inf && !tot_not;
				st[top][2] = num1 > num2;
				// st[][1] 判断是否对复杂度有贡献
				// st[][2] 判断以下嵌套的是不是展不开
			}
			else { // E
				
				// 处理栈
				vis[st[top][0]] = 0;
				if(st[top][1]) --fzd;
				if(st[top][2]) --tot_not;
				--top;

			}
		}

		if(ERR_flag || top) puts("ERR");
		else if(mx != tim) puts("No");
		else puts("Yes");

		// Debug
		// printf("ERR_flag : %d top : %d\n", ERR_flag, top);
		// printf("Time: %d O: %d\n", tim, mx);
		// printf("tot_not: %d\n", tot_not);

	}

}