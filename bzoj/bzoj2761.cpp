#include <bits/stdc++.h>

using namespace std ;

#define ll long long

set < ll > st , st2 ;

int main() {
	int t , n ;
	scanf( "%d" , &t ) ;
	while( t -- ) {
		scanf( "%d" , &n ) ;
		for( int i = 1 ; i <= n ; i ++ ) {
			ll x ;
			scanf( "%lld" ,&x ) ;
			if( st.find( x ) == st.end() ) printf( "%lld " , x ) ,st.insert( x ) ;
	 	}
		puts( "" ) ;
		st = st2 ;
	}
}
