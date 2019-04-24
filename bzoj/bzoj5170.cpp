#include <bits/stdc++.h>

using namespace std ;

#define N 200010
#define lowbit( i ) i&(-i)

int ans[ N ] , n , k , rk[ N ] , f[ N ] , c[ N ] ;
struct node {
    int val , id ;
}a[ N ] ;

//每次冒泡排序都会把当前数前移一位（如果前面有比它大的数的话） 
//用树状数组维护当前有几个比它大的
//如果比它大的超过k个那么直接前移k位就好了（k次都有比当前大的数，移动了k位） 
//最后剩下的位置一位一位地去填，从小到大填 

bool cmp( node a, node b ) {
    return a.val < b.val ;
}

void add( int x , int val ) {
    for( int i = x ; i <= n ; i += lowbit( i ) ) 
        c[ i ] += val ;
}

int query( int x ) {
    int ans = 0 ;
    for( int i = x ; i ; i -= lowbit( i ) ) ans += c[ i ] ;
    return ans ;
}

int main() {
    scanf( "%d%d" , &n , &k ) ;
    for( int i = 1 ; i <= n ; i ++ ) {
        scanf( "%d" , &a[ i ].val ) ;
        a[ i ].id = i ;
    }
    sort( a + 1 , a + n + 1 , cmp ) ;
    rk[ a[ 1 ].id ] = 1 ;
    for( int i = 2 ; i <= n ; i ++ ) {
        if( a[ i ].val == a[ i - 1 ].val ) rk[ a[ i ].id ] = rk[ a[ i - 1 ].id ] ;
        else rk[ a[ i ].id ] = i ;
    }
    for( int i = 1 ; i <= n ; i ++ ) {
        add( rk[ i ] , 1 ) ;
        f[ i ] = query( n ) - query( rk[ i ] ) ;
        if( f[ i ] > k ) ans[ i - k ] = a[ rk[ i ] ].val ;
    }
    int cur = 1 ;
	for( int i = 1 ; i <= n ; i ++ ) {
		if( f[ a[ i ].id ] <= k ) {
			while( cur <= n && ans[ cur ] ) cur ++ ;
			ans[ cur ] = a[ i ].val ;
		}
	}
	for( int i = 1 ; i <= n ; i ++ ) {
		printf( "%d\n" ,ans[ i ] ) ;
	}
	return 0 ;
} 
