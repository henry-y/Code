#include <bits/stdc++.h>

using namespace std ;

#define lc ( rt << 1 | 1 )
#define rc ( rt << 1 )
const int N = 1e5 + 10 ;

int n ;
int c[ N ] , t[ N << 2 ] ;
int ans ;
vector < int > vt[ N ] ;

void add( int l , int r , int rt , int x ) {
	t[ rt ] ++ ;
	int mid = ( l + r ) >> 1 ;
	if( l == r ) return ;
	if( x <= mid ) add( l , mid , lc , x ) ;
	else add( mid + 1 , r , rc , x ) ;
}

int query( int l , int r , int rt , int x ) {
	if( l == r ) return l ;
	int mid = ( l + r ) >> 1 ;
	if( t[ lc ] >= x ) return query( l , mid , lc , x ) ;
	else return query( mid + 1 , r , rc , x - t[ lc ] ) ;
}

int main() {
	scanf( "%d" , &n ) ;
	for( int i = 1 ; i <= n ; i ++ ) scanf( "%d" , &c[ i ] ) , vt[ n - c[ i ] ].push_back( i ) ;
	ans = n ;
	for( int i = 1 ; i <= n ; i ++ ) {
		for( int j = 0 , len = vt[ i ].size() ; j < len ; j ++ ) add( 1 , n , 1 , vt[ i ][ j ] ) ;
		if( t[ 1 ] >= i ) ans = min( ans , query( 1 , n , 1 , i ) ) ;
	}
	printf( "%d\n" , n - ans ) ;
	return 0 ;
} 
