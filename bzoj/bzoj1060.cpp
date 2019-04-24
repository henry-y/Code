#include <bits/stdc++.h>

using namespace std ;

#define N 1000010
#define inf 0x3f3f3f3f
#define ll long long
#define int long long

int n , s , fa[ N ] , f[ N ] ;
int head[ N ] , cnt ; 
ll ans = 0 ;
struct node {
	int to , nxt , v ;
}e[ N ] ;
//f[i]表示i节点到叶子节点所需要花的最长时间 

void ins( int u , int v , int w ) {
	e[ ++ cnt ].to = v ;
	e[ cnt ].nxt = head[ u ] ;
	e[ cnt ].v = w ;
	head[ u ] = cnt ;
} 

void dfs1( int u ) {
	for( int i = head[ u ] ; i ; i = e[ i ].nxt ) {
		if( e[ i ].to == fa[ u ] ) continue ;
		fa[ e[ i ].to ] = u ;
		dfs1( e[ i ].to ) ;
	}
}

void dfs( int u ) {
	for( int i = head[ u ] ; i ; i = e[ i ].nxt ) {
		if( e[ i ].to == fa[ u ] ) continue ;
		dfs( e[ i ].to ) ;
		f[ u ] = max( f[ u ] , f[ e[ i ].to ] + e[ i ].v ) ; 
	}
	for( int i = head[ u ] ; i ; i = e[ i ].nxt ) {
		if( e[ i ].to != fa[ u ] ) {
			ans += f[ u ] - f[ e[ i ].to ] - e[ i ].v ;
		} 
	}
}

main() {
	scanf( "%lld%lld" , &n , &s ) ;
	for( int i = 1 ; i < n ; i ++ ) {
		int a , b , t ;
		scanf( "%lld%lld%lld" , &a , &b , &t ) ;
		ins( a , b , t ) ;
		ins( b , a , t ) ;
	}
	dfs1( s ) ;
	dfs( s ) ;
	printf( "%lld" , ans ) ;
	return 0 ;
} 
