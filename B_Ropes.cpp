#include <bits/stdc++.h>
#define lol long long
using namespace std;

vector<lol> a;
lol n, k;
bool check(long double x)
{
    lol c = 0;
    for (lol i = n - 1; i >= 0; i--)
    {
        c += floor(a[i] / x);
    }
    return c >= k;
}

int main()
{

    cin >> n >> k;

    for (lol i = 0; i < n; i++)
    {
      lol t;
      cin>>t;
      a.push_back(t);
    }

    long double s = 0;
    long double e = 1e8;
    lol c = 100;
    while (c--)
    {

        long double m = (s + e) / (long double)2;
        if (check(m))
        {
            s = m;
        }
        else
            e = m;

        
    }

    cout <<setprecision(20)<< s;

    return 0;
}