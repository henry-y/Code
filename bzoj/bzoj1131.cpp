#include <bits/stdc++.h>

using namespace std ;

#define ll long long
#define N 2000010

int ans = 0 , n ;
int cnt , head[ N ] ;
ll f[ N ] , siz[ N ] , dep[ N ] ;
struct node {
	int to , nxt ;
}e[ N ];

void ins( int u , int v ) {
	e[ ++ cnt ].to = v ;
	e[ cnt ].nxt = head[ u ] ;
	head[ u ] = cnt ;
}

void dfs1( int u , int fa ) {
	siz[ u ] = 1 ;
	f[ u ] = dep[ u ] ;
	for( int i = head[ u ] ; i ; i = e[ i ].nxt ) {
		if( e[ i ].to == fa ) continue ;
		dep[ e[ i ].to ] = dep[ u ] + 1 ;
		dfs1( e[ i ].to , u ) ;
		siz[ u ] += siz[ e[ i ].to ] ;
		f[ u ] += f[ e[ i ].to ] ;
	}
}

void dfs2( int u , int fa ) {
	for( int i = head[ u ] ; i ; i = e[ i ].nxt ) {
		if( e[ i ].to == fa ) continue ;
		f[ e[ i ].to ] = f[ u ] + n - 2 * siz[ e[ i ].to ] ; 
		dfs2( e[ i ].to , u ) ;
	}
}

int main() {
	scanf( "%d" , &n ) ;
	for( int i = 1 ; i < n ; i ++ ) {
		int x , y ;
		scanf( "%d%d" , &x , &y ) ;
		ins( x , y ) ;ins( y , x ) ;
	}
	dfs1( 1 , 0 ) ;
	dfs2( 1 , 0 ) ;
	for( int i = 1 ; i <= n ; i ++ ) {
		if( f[ i ] > f[ ans ] ) ans = i ;
	}
	printf( "%d\n" , ans ) ;
} 
