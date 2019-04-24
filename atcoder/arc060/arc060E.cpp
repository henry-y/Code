#include <bits/stdc++.h>

using namespace std ;

#define N  100010

int n , L , m ;
int a[ N ] , to[ N ] ;
int num , block , belong[ N ] ; 
int nxt[ N ] , val[ N ] ;

int find( int x ) {//二分 
	int l = x + 1 , r = n , ans = 0 ;
	while( l <= r ) {
		int mid = ( l + r ) >> 1 ;
		if( a[ mid ] - a[ x ] <= L ) l = mid + 1 , ans = mid ;
		else r = mid - 1 ;
	}
	return ans ;
}

int main() {
	scanf( "%d" , &n ) ;
	for( int i = 1 ; i <= n ; i ++ ) {
		scanf( "%d" , &a[ i ] ) ;
	}
	sort( a + 1 , a + n + 1 ) ;
	scanf( "%d%d" , &L , &m ) ;
	for( int i = 1 ; i < n ; i ++ ) {
		to[ i ] = find( i ) ;
	}
	to[ n ] = n + 1 ;//to数组为一天能走多少个酒店 
	block = sqrt( n ) ;//block为块的大小 
	num = n / block ;//num为块数 
	if( n % block ) num ++ ;
	for( int i = 1 ; i <= n ; i ++ ) {
		belong[ i ] = ( i - 1 ) / block + 1 ;//每个数属于哪个块 
	}
	for( int i = 1 ; i < n ; i ++ ) {
		int t = i , sp = 0 ;
		while( belong[ t ] == belong[ i ] ) {
			t=to[ t ] ;
			sp ++ ;
		}
		val[ i ] = sp ;//val[i]表示从i这个点跳出当前块要花多少天 
		nxt[ i ] = t ;//nxt[i]表示从i这个点跳出当前块之后到了哪个点 
		if( i >= block * ( num - 1 ) + 1 ) val[ i ] -- , nxt[ i ] -- ;
		//这是针对最后一个块的 
	}
	for( int i = 1 ; i <= m ; i ++ ) {
		int x , y  , ans = 0 ;
		scanf( "%d%d" , &x ,&y ) ;
		if( x > y )swap( x , y ) ;
		while( belong[ x ] < belong[ y ] ) {
			ans += val[ x ] ;
			x = nxt[ x ] ;
		}//整块整块地跳，最坏复杂度sqrt(n) 
		while( x < y ) {
			x = to[ x ] ;
			ans ++ ;	
		} //在散块中暴力地去跳，最坏复杂度sqrt(n) 
		printf( "%d\n" , ans  ) ;
	}
	return 0 ;
} 
