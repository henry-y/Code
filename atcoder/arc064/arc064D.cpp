#include <bits/stdc++.h>

using namespace std ;

#define N 100010
char a[ N ] ;

int main() {
	int cnt = 0 ;
	scanf( "%s" , a + 1 ) ;
	int n = strlen( a + 1 ) , k = n & 1 ; 
	puts( abs( k - ( a[ n ] == a[ 1 ] ) ) & 1 ? "First" : "Second" ) ; 
} 
