#include <bits/stdc++.h>

using namespace std ;

const int N = 1e5 + 10 ;

int n , m ;
char ch[ N ][ 10 ] ;
int t[ N ] ;

int main() {
	scanf( "%d%d" , &n , &m ) ;
	for( int i = 1 ; i <= n ; i ++ ) {
		scanf( "%s%d" , ch[ i ] , &t[ i ] ) ;
	}
	int tot = 0 , ans = 0 ;
	for( int i = 30 ; i >= 0 ; i -- ) {
		int t1 = ( 1ll << i ) , t2 = 0 ;
		for( int j = 1 ; j <= n ; j ++ ) {
			if( ch[ j ][ 0 ] == 'O' ) t1|=(t[j]&(1ll<<i)),t2|=(t[j]&(1ll<<i));
			if( ch[ j ][ 0 ] == 'A' ) t1&=(t[j]&(1ll<<i)),t2&=(t[j]&(1ll<<i));
			if( ch[ j ][ 0 ] == 'X' ) t1^=(t[j]&(1ll<<i)),t2^=(t[j]&(1ll<<i));
		}
		if( t1 > t2 && tot + ( 1ll << i ) <= m ) tot += 1ll << i , ans += t1 ;
		else  ans += t2 ;
	}
	printf( "%d\n" , ans ) ;
} 
