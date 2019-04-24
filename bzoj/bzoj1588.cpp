#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <cstdlib>

using namespace std;

#define N 100010
#define ll long long
#define inf 0x3f3f3f3f
#define lc ch[ u ][ 0 ]
#define rc ch[ u ][ 1 ]
#define il inline

il void in( int &x ) {
	x = 0 ; int f = 1 ; char c = getchar() ;
	while( c < '0' || c >'9' ) {
		if( c == '-' ) f = - f ;
		c = getchar() ;
	}
	while( c >= '0' && c <= '9' ) {
		if( c >= '0' && c <= '9' ) x = ( x << 1 ) +( x << 3 ) + c - '0' ;
		c = getchar() ; 
	}
	x *= f ;
}

int n , sz , root ;
int ch[ N ][ 2 ] , key[ N ] , rnd[ N ] ;

void rotate( int &u , int d ) {
	int v = ch[ u ][ d^1 ] ;
	ch[ u ][ d^1 ] = ch[ v ][ d ] ;
	ch[ v ][ d ] = u ;
	u = v ;
}

void insert( int &u ,int val ) {
	if( !u ) {
		u = ++ sz ;
		lc = rc = 0 ;
		key[ u ] = val ;
		rnd[ u ] = rand() ;
		return ;
	}	
	if( key[ u ] == val ) return ;
	int d = key[ u ] < val ;
	insert( ch[ u ][ d ] , val ) ;
	if( rnd[ ch[ u ][ d ] ] < rnd[ u ] ) rotate( u , d^1 ) ;
}

int pre( int val ) {
	int u = root , pre = -inf ;
	while( u ) {
		if( val >= key[ u ] ) pre = key[ u ] , u = rc ;
		else u = lc ;
	}
	return pre ;
}

int nxt( int val ) {
	int u = root , nxt = inf ;
	while( u ) {
		if( key[ u ] <= val ) u = rc ;
		else nxt = key[ u ] , u = lc ;
	}
	return nxt ;
}

int main() {
	in( n ) ;
	int ans = 0 ;
	for( int i = 1 ; i <= n ; i ++ ) {
		int x ;
		if( scanf( "%d" , &x ) == EOF ) x = 0 ;
		int a = pre( x ) , b = nxt( x ) ;
		if( i == 1 ) ans += x ;
		else ans += min( x - a ,b - x ) ;
		insert( root , x ) ;
	}
	printf( "%d\n" , ans ) ;
	return 0 ;
}
