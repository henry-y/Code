#include <bits/stdc++.h>

using namespace std ;

#define N 100010
#define inf 0x3f3f3f3f
#define mod 10007

int n , m ;
int a[ N ] , f[ 2 ][ N ] , q[ N ] , sum[ N ] ;

bool check( int x ) {
	int sum = 0 , cnt = 0 ;
	for( int i = 1 ; i <= n ; i ++ ) {
		if( sum + a[ i ] > x ) sum = 0 , cnt ++ ;
		sum += a[ i ] ;
		if( a[ i ] > x ) return 0 ;
		if( cnt > m ) return 0 ;
	}
	return 1 ;
}

int main() {
	scanf( "%d%d" , &n , &m ) ;
	int l = inf , r , ans ;
	for( int i = 1 ; i <= n ; i ++ ) {
		scanf( "%d" , &a[ i ] ) ;
		l = min( l , a[ i ] ) ;
		sum[ i ] = sum[ i - 1 ] + a[ i ] ;
	}
	r = sum[ n ] ;
	while( l <= r ) {
		int mid = ( l + r ) >> 1 ;
		if( check( mid ) ) ans = mid , r = mid - 1 ;
		else l = mid + 1 ;
	}
	printf( "%d " , ans ) ;
	f[ 0 ][ 0 ] = 1 ;
	int ans2 = 0 ;
	for( int i = 1 ; i <= m ; i ++ ) {
		int pre = i&1 , cur = pre^1 , tot = f[ cur ][ 0 ] ;
		l = 1 , r = 1 ;
		q[ 1 ] = 0 ;
		for( int j = 1 ; j <= n ; j ++ ) {
			while( l <= r && sum[ j ] - sum[ q[ l ] ] > ans ) 
				tot = ( tot - f[ cur ][ q[ l ++ ] ] + mod ) % mod ;
			f[ pre ][ j ] = tot ;
			q[ ++ r ] = j ;
			tot = ( tot + f[ cur ][ j ] + mod ) % mod ;
		}
		for( int j = n - 1 ; j ; j -- ) {
			if( sum[ n ] - sum[ j ] > ans ) break ;
			ans2 = ( ans2 + f[ pre ][ j ] + mod ) % mod ;
		}
		memset( f[ cur ] , 0 , sizeof( f[ cur ] ) ) ;
	}
	printf( "%d\n" , ans2 ) ;
	return 0 ;
}
