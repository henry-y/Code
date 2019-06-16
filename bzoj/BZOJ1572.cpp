#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
#include <map>
#include <set>

using namespace std ;

#define N 100010
#define int long long

int n , m ;
struct node {
    int d,p ;
    bool operator < ( const node &x ) const { return p>x.p; }
} a[ N ] ;

bool cmp( node a , node b ) {
    return a.d==b.d?a.p<b.p:a.d<b.d;
}

priority_queue< node > q ;

signed main() {
    scanf( "%lld" , &n ) ;
    for( int i = 1 ; i <= n ; i ++ ) {
        scanf( "%lld%lld" , &a[i].d , &a[i].p ) ;
    }
    sort(a+1,a+n+1,cmp);
    int ans = 0 ;
    for( int i = 1 ; i <= n ; i ++ ) {
        if( a[i].d<=q.size() ) {
            if( q.top().p<a[i].p ) {
                ans += a[i].p-q.top().p ; 
                q.pop() ; 
                q.push(a[i]) ;
            }
        } else q.push(a[i]) , ans += a[ i ].p ;
    }
    printf( "%lld\n" , ans ) ;
}