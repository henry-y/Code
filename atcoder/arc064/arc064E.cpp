#include <bits/stdc++.h>

using namespace std ;

#define N 2010000
#define ld long double
#define inf 0x3f3f3f3f
#define int long long

int xt , yt ;
int n ;
int head[ 5000000 ] , cnt ;
int  X[ N ] , Y[ N ] , r[ N ] ;
struct node {
	int to , nxt ;
	ld v ;
}e[ 5000000 ] ;

ld dist( int i , int j ) {
	ld t = sqrt(pow((X[i]-X[j]),2)+pow(Y[i]-Y[j],2))-r[i]-r[j];
	if( t < 0 ) t = (ld)0 ;
	return t ;
}

void ins( int u , int v , ld w ) {
	e[ ++ cnt ].to = v ;
	e[ cnt ].nxt = head[ u ] ;
	e[ cnt ].v = w ;
	head[ u ] = cnt ;
}

bool vis[ N ] ;
ld d[ N ] ;
int q[ N * 100 ] ;

void spfa() {
	int l = 1 , r = 2 ; 
	for( int i = 1 ; i <= n ; i ++ ) d[ i ] = inf ;
	memset( vis , 0 , sizeof( vis ) ) ;
	q[ 1 ] = 1 ; vis[ 1 ] = 1 ; d[ 1 ] = 0 ;
	while( l != r ) {
		int u = q[ l ++ ] ; 
		vis[ u ] = 0 ;
		if( l == 100000 ) l = 1 ;
		for( int i = head[ u ] ; i ; i = e[ i ].nxt ) {
			int v = e[ i ].to ;
			if( d[ v ] > d[ u ] + e[ i ].v ) {
				d[ v ] = d[ u ] + e[ i ].v ;
				if( !vis[ v ] ) vis[ v ] = 1 , q[ r ++ ] = v ;
				if( r == 100000 ) r = 1 ;
			}
		}
	}
}

main() {
	scanf( "%lld%lld%lld%lld" , &X[ 1 ] , &Y[ 1 ] , &xt , &yt ) ;
	scanf( "%lld" , &n ) ;
	n += 2 ;
	r[ 1 ] = 0 ;
	r[ 2 ] = 0 ;
	X[ 2 ] = xt ; 
	Y[ 2 ] = yt ;
	ins( 1 , 2 , dist( 1 , 2 ) ) ;
	ins( 2 , 1 , dist( 2 , 1 ) ) ;
	for( int i = 3 ; i <= n ; i ++ ) {
		scanf( "%lld%lld%lld" , &X[ i ] , &Y[ i ] , &r[ i ] ) ;
	}
	for( int i = 1 ; i <= n; i ++ ) {
		for( int j = i + 1 ; j <= n ; j ++ ) {
			ins( i , j , dist( i , j ) ) ;
			ins( j , i , dist( i , j ) ) ;
		}
	}
	spfa( ) ;
	printf( "%.15Lf" , d[ 2 ] ) ;
} 

