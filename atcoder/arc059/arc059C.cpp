#include <bits/stdc++.h>

using namespace std ;

int n , a[ 200 ] ;
long long sum = 0 , ans = 0x3f3f3f3f ;
long long x[ 10000 ] ;
 
int main() {
	scanf( "%d" , &n ) ;
	for( int i = 1 ; i <= n ; i ++ ) {
		scanf( "%d" , &a[ i ] ) ;
		sum += a[ i ] ;
	}
	int t = sum / n ;
	int t1 = 0 , t3 = -100 ;
	while( t3 <= t ) {
		t1 = t3 ;
		t3 += n ;
	}
	for( int i = 1 ; i <= n ; i ++ ) {
		int cnt = 0 ;
		for( int j = t1 ; j <= t3 ; j ++ ) {
			x[ ++ cnt ] += abs( a[ i ] - j ) * abs( a[ i ] - j ) ;
		}
	}
	int cnt = 0 ;
	for( int j = t1 ; j <= t3 ; j ++ ) {
		ans = min( ans , x[ ++ cnt ] ) ;
	}
	printf( "%lld" , ans ) ;
	return 0 ;
}
