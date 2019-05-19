#include <bits/stdc++.h>
using namespace std;
char s[10];
int main() {
	cin >> s;
	for (int i = 0; i < 4; ++i) s[i] -= '0';
	int a = s[0] * 10 + s[1];
	int b = s[2] * 10 + s[3];
	if (1 <= a && a <= 12) {
		if(1 <= b && b <= 12) puts("AMBIGUOUS");
		else puts("MMYY");
	} else {
		if(1 <= b && b <= 12) puts("YYMM");
		else puts("NA");
	}
	return 0;
}