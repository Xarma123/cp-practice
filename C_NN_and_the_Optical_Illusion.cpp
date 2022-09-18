#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    long double n,r;
    cin>>n>>r;

    long double v = sinl( 2 * acos(0.0)/(long double)n);
    r*=v;
    r= r/(long double)(1-v);
    cout<<setprecision(11)<<r;


    return 0;
}