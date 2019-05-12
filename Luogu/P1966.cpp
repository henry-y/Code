#include <bits/stdc++.h>

#define ll long long
#define inf 0x3f3f3f3f
#define il inline

namespace io {

    #define in(a) a=read()
    #define out(a) write(a)
    #define outn(a) out(a),putchar('\n')

    #define I_int long long
    inline I_int read() {
        I_int x = 0 , f = 1 ; char c = getchar() ;
        while( c < '0' || c > '9' ) { if( c == '-' ) f = -1 ; c = getchar() ; }
        while( c >= '0' && c <= '9' ) { x = x * 10 + c - '0' ; c = getchar() ; }
        return x * f ;
    }
    char F[ 200 ] ;
    inline void write( I_int x ) {
        if( x == 0 ) { putchar( '0' ) ; return ; }
        I_int tmp = x > 0 ? x : -x ;
        if( x < 0 ) putchar( '-' ) ;
        int cnt = 0 ;
        while( tmp > 0 ) {
            F[ cnt ++ ] = tmp % 10 + '0' ;
            tmp /= 10 ;
        }
        while( cnt > 0 ) putchar( F[ -- cnt ] ) ;
    }
    #undef I_int

}
using namespace io ;

using namespace std ;

const int N = 100010;
const int mod = 99999997;

int n, a[N], b[N], p[N], C[N];
int c[N];

namespace BIT {
    int lowbit(int x) {
        return x & -x;
    }
    void add(int x, int v) {
        for(int i = x; i <= n; i += lowbit(i)) c[i] += v, c[i] %= mod;
    }
    int query(int x) {
        int sum = 0;
        for(int i = x; i; i -= lowbit(i)) sum += c[i], sum %= mod;
        return sum;
    }
}

int main() {
    in(n);
    for(int i = 1; i <= n; ++i) in(a[i]), C[i] = a[i];
    sort(C + 1, C + n + 1);
    for(int i = 1; i <= n; ++i) a[i] = lower_bound(C + 1, C + n + 1, a[i]) - C; 
    for(int i = 1; i <= n; ++i) in(b[i]), C[i] = b[i];
    sort(C + 1, C + n + 1);
    for(int i = 1; i <= n; ++i) b[i] = lower_bound(C + 1, C + n + 1, b[i]) - C; 
    for(int i = 1; i <= n; ++i) p[b[i]] = i;
    for(int i = 1; i <= n; ++i) a[i] = p[a[i]];
    int ans = 0;
    for(int i = 1; i <= n; ++i) {
        ans += BIT::query(n) - BIT::query(a[i]);
        ans %= mod;
        BIT::add(a[i], 1);
    }
    outn(ans);
} 