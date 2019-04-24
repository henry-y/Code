#include<bits/stdc++.h>
using namespace std;

const int N = 2e5+5 ;
char s1[ N ] , s2[ N ] ;
int a[ N ] , b[ N ] ;

int main() {
	scanf( "%s %s" , s1 , s2 ) ;
	int len1 = strlen( s1 + 1  ) , len2 = strlen( s2 + 1 ) ;
	if( len1 != len2 ) return puts( "No" ) , 0 ; 
	for( int i = 1 ; i <= len1 ; i ++ ) {
		if( !a[ s1[ i ] - 'a' ] && !b[ s2[ i ] - 'a' ] ) {
			a[ s1[ i ] - 'a' ] = s2[ i ] - 'a' ;
			b[ s2[ i ] - 'a' ] = s1[ i ] - 'a' ;
		}else if( a[ s1[ i ] - 'a' ] == s2[ i ] - 'a' && b[ s2[ i ] - 'a' ] == s1[ i ] - 'a' ) continue ;
		else if( a[ s1[ i ] - 'a' ] != s2[ i ] - 'a' || b[ s2[ i ] - 'a' ] != s1[ i ] - 'a' ) return puts("No"),0 ; 
	}
	return puts("Yes") , 0 ;
}

