#include <cstdio>

long long mod = 1000000007 ;

int main(void)
{
    long long a, b ;

    scanf("%I64d%I64d", &a, &b) ;

    long long B = (b*(b-1)/2) % mod ;
    long long A1 = (a*(a+1)/2) % mod ;
    long long A = (A1*b+a) % mod ;
    long long answer = (A*B) % mod ;

    printf("%I64d\n", answer) ;

    return 0 ;
}