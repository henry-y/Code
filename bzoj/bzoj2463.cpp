#include <cstdio>

using namespace std;

int n;

int main(){
	while(scanf("%d",&n)==1&&n){
		(n&1)?puts("Bob"):puts("Alice");
	}
	return 0;
} 
