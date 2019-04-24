#include <bits/stdc++.h>

using namespace std;

int main(){
	int n , ans=0 ;
	scanf( "%d" , &n ) ;
	while( n != 1 ){
		if( (n&1) ) n = n * 3 + 1;
		else n = n >> 1 ;
		ans ++ ;
	}
	printf("%d\n",ans);
}
