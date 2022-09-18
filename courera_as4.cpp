#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long a;
    cin >> a;
    long long ans = 0;
    ans += a / 10;
    a = a%10;
    ans += a / 5;
    a = a % 5;
    ans += a / 1;
    a = a % 1; 
    cout<<ans;

    return 0;
}