#include <cmath>
#include <cstdio>
#include <algorithm>

using namespace std;
const int N = 110;
const double eps = 1e-5;

int n;
double b[N], a[N][N];

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= n; ++j) scanf("%lf", &a[i][j]);
		scanf("%lf", &b[i]);
	}
	for(int i = 1; i <= n; ++i) {
		// 消 x_i 这一元
		
		for(int j = i; j <= n; ++j) {
			if(fabs(a[j][i]) > eps) {
				for(int k = 1; k <= n; ++k) {
					swap(a[i][k], a[j][k]);
				}
				swap(b[i], b[j]);
			}
		}

		for(int j = 1; j <= n; ++j) {
			if(i == j) continue;
			// 在第j行消去 x_i 的系数
			double res = (double) a[j][i] / a[i][i];
			for(int k = i; k <= n; ++k) 
				a[j][k] -= res * a[i][k];
			b[j] -= res * b[i];
		}

	}
	for(int i = 1; i <= n; ++i) {
		if(a[i][i] == 0 && b[i] == 0) return puts("No Solution"), 0;
	}
	for(int i = 1; i <= n; ++i) {
		printf("%.2lf\n", b[i] / a[i][i]);
	}
	return 0;
}