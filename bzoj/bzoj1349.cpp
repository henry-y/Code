#include <bits/stdc++.h>

using namespace std ;

#define ll long long

ll n ; 

int main() {
	scanf( "%lld" , &n ) ;
	ll m = sqrt( n ) ;
	if( m * m < n ) m ++ ;
	printf( "%lld\n" , m ) ; 
}
