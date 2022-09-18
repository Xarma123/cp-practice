#include <bits/stdc++.h>
#define lol long long
using namespace std;

int n;
lol a, b;
lol x[100005];
int main()
{
    scanf("%d%lld%lld", &n, &a, &b);
    for (int i = 0; i < n; ++i)
    {
        scanf("%lld", &x[i]);
    }
    for (int i = 0; i < n; ++i)
    {
        lol p = x[i] * a / b;
        printf("%lld ", x[i] - p * b / a - (p * b % a != 0));
    }
    return 0;
}