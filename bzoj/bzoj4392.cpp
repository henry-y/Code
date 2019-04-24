#include <bits/stdc++.h>

using namespace std ;

#define N 200010
#define inf 0x3f3f3f3f
#define lc rt<<1
#define rc rt<<1|1
#define int long long 

int n , m ;
int a[ N ] ;
struct tree {
	int l , r , sum , min , add ;
}t[ N << 2 ] ;

void build( int l , int r , int rt ) {
	t[ rt ].l = l ; t[ rt ].r = r ;
	if( l == r ) {
		t[ rt ].min = a[ l ] ;
		t[ rt ].sum = a[ l ] ;
		return ;
	}
	int mid = ( l + r ) >> 1 ;
	build( l , mid , lc ) ;
	build( mid + 1 , r , rc ) ;
	t[ rt ].sum = t[ lc ].sum + t[ rc ].sum ;
	t[ rt ].min = min( t[ lc ].min , t[ rc ].min ) ;
}

void pushdown( int ln , int rn ,int rt ) {
	if( t[ rt ].add ) {
		int x = t[ rt ].add ;
		t[ lc ].add += x ;
		t[ rc ].add += x ;
		t[ lc ].sum += ln * x ;
		t[ rc ].sum += rn * x ;
		t[ lc ].min += x ;
		t[ rc ].min += x ;
		t[ rt ].add = 0 ;
	}
}

void upd( int L , int R , int c , int rt ) {
	int l = t[ rt ].l , r = t[ rt ].r , mid = ( l + r ) >> 1 ;
	if( L <= l && r <= R ) {
		t[ rt ].sum += c * ( r - l + 1 ) ;
		t[ rt ].add += c ;
		t[ rt ].min += c ;
		return ;
	} 
	pushdown( mid - l + 1 , r - mid , rt ) ;
	if( L <= mid ) upd( L , R , c , lc ) ;
	if( R > mid ) upd( L , R , c , rc ) ;
	t[ rt ].sum = t[ lc ].sum + t[ rc ].sum ;
	t[ rt ].min = min( t[ lc ].min , t[ rc ].min ) ;
}

int query( int L , int R , int rt ) {
	int l = t[ rt ].l , r = t[ rt ].r , mid = ( l + r ) >> 1 , ans = 0 ;
	if( L <= l && r <= R ) return t[ rt ].sum ; 
	pushdown( mid - l + 1 , r - mid , rt ) ;
	if( L <= mid ) ans += query( L , R , lc ) ;
	if( R > mid ) ans += query( L , R , rc ) ;
	return ans ;
}

int query_min( int L , int R , int rt ) {
	int l = t[ rt ].l , r = t[ rt ].r , mid = ( l + r ) >> 1 , ans = inf ;
	if( L <= l && r <= R ) return t[ rt ].min ;
	pushdown( mid - l + 1 , r - mid , rt ) ;
	if( L <= mid ) ans = min( ans , query_min( L ,R , lc ) ) ;
	if( R > mid ) ans = min( ans , query_min( L ,R , rc ) ) ;
	return ans ;
}

main() {
	scanf( "%lld%lld" , &n , &m ) ;
	for( int i = 1 ; i <= n ; i ++ ) {
		scanf( "%lld" , &a[ i ] ) ;
	}
	build( 1 , n , 1 ) ;
	for( int i = 1 ; i <= m ;i ++ ) {
		char ch[ 10 ] ;
		int x , y ;
		scanf( "%s%lld%lld" , ch , &x , &y ) ;
		if( ch[ 0 ] == 'M' ) {
			printf( "%lld\n" , query_min( x , y , 1 ) ) ;
		}else if( ch[ 0 ] == 'S' ) {
			printf( "%lld\n" , query( x , y  , 1 ) ) ;
		}else {
			int t ;
			scanf( "%lld" , &t ) ;
			upd( x ,y , t , 1 ) ;
		}
	}
	return 0 ;
} 
