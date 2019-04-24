#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cstring>

inline void read( int &x ){
    x = 0 ; int f = 1 ; char c = getchar() ;
    while( c < '0' || c > '9' ) {
        if( c == '-' ) f = -1 ;
        c = getchar() ;
    }
    while( c >= '0' && c <= '9' ) {
        x = (x << 1) + (x << 3) + c - 48 ;
        c = getchar() ;
    }
    x *= f ;
}

using namespace std ;

#define N 100010
#define il inline
#define ll long long
#define inf 0x3f3f3f3f
#define lc ch[u][0]
#define rc ch[u][1]

int n , sz = 0 , root ;
int ch[ N ][ 2 ] , rnd[ N ] , cnt[ N ] , key[ N ] , siz[ N ];
//这里的rnd是小根堆 

il void upd( int u ) {
	siz[ u ] = siz[ lc ] +siz[ rc ] + cnt[ u ] ;
}

il void rotate( int &u , int d ){
	//0左1右 
	int v = ch[ u ][ d^1 ] ;
	ch[ u ][ d^1 ] = ch[ v ][ d ] ;
	ch[ v ][ d ] = u ;
	upd( u ) ; upd( u = v ) ; 
}

il void insert( int &u , int val ) {
	if( !u ) {
		u = ++ sz ;
		lc = rc = 0 ;
		siz[ u ] = cnt[ u ] = 1 ;
		rnd[ u ] = rand() ;
		key[ u ] = val ;
		return ;
	}
	if( key[ u ] == val ) {
		siz[ u ] ++ ;
		cnt[ u ] ++ ;
		return ;
	}
	int d = key[ u ] < val ;
	insert( ch[ u ][ d ] , val ) ;
	siz[ u ] ++ ;
	if( rnd[ ch[ u ][ d ] ] < rnd[ u ] ) rotate( u , d^1 ) ;
}

il void del( int &u , int val ) {
	if( !u ) return ;
	if( key[ u ] == val ) {
		if( cnt[ u ] > 1 ) {
			cnt[ u ] -- ;
			siz[ u ] -- ;
			return ;
		}
		if( !lc || !rc ) {
			u = lc ? lc : rc ;
			return ;
		}
		if( rnd[ lc ] > rnd[ rc ] ) rotate( u , 0 ) ;
		else rotate( u , 1 ) ;
		del( u , val ) ;
		return ;
	}
	int d = key[ u ] < val ;
	del( ch[ u ][ d ] , val ) ;
	siz[ u ] -- ;
}

il int find_rnk( int val ) {
	int u = root , rnk = 1 ;
	while( u ) {
		if( key[ u ] > val ) u = lc ;
		else if( key[ u ] < val ) rnk += siz[ lc ] + cnt[ u ] , u = rc ;
		else return rnk + siz[ lc ] ;
	}
	return 0 ;
}

il int find_key( int rnk ) {
	int u = root ;
	while( u ) {
		if( rnk <= siz[ lc ] ) u = lc ;
		else if( rnk > siz[ lc ] + cnt[ u ] ) rnk -= siz[ lc ] + cnt[ u ] , u = rc ;
		else return key[ u ] ;
	}
	return 0 ;
}

il int pre( int val ) {
	int u = root , pre = 0 ;
	while( u ) {
		if( val > key[ u ] ) pre = key[ u ] , u = rc ;
		else u = lc ;
	}
	return pre ; 
}

il int nxt( int val ) {
	int u = root , nxt = 0 ;
	while( u ) {
		if( key[ u ] <= val ) u = rc ;
		else nxt = key[ u ] , u = lc ;
	}
	return nxt ;
}

int main() {
	read( n ) ;
	while( n -- ) {
		int opt , x ;
		read( opt ) ; read( x ) ;
		if( opt == 1 ) insert( root , x ) ;
		if( opt == 2 ) del( root , x ) ;
		if( opt == 3 ) printf( "%d\n" , find_rnk( x ) ) ;
		if( opt == 4 ) printf( "%d\n" , find_key( x ) ) ;
		if( opt == 5 ) printf( "%d\n" , pre( x ) ) ;
		if( opt == 6 ) printf( "%d\n" , nxt( x ) ) ;
	}
	return 0 ;
}
