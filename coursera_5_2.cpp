#include <bits/stdc++.h>
#define lol long long
using namespace std;
struct data
{
    lol a;
    lol b;
};
data ans(lol a[], lol n)
{
    if (n == 0)
    {
        data x;
        x.a = -1;
        x.b = -1;
        return x;
    }
    if (n == 1)
    {
        data x;
        x.a = *a;
        x.b = 1;
        return x;
    } 
   
    data al = ans(a, n / 2);
    data ar=
ans(a + (n / 2), n - n / 2);
    for (long long i = 0; i < n; i++)
    {
        if (i < n / 2)
        {
            if (a[i] == ar.a)
            {
                ar.b++;
            }
        }
        else
        {
            if (a[i] == al.a)
                al.b++;
        }
    }
    if (al.b > n / 2)
    {
        return al;
    }
    else if (ar.b > n / 2)
        return ar;
    else
    {
        data x;
        x.a = -1;
        x.b = -1;
        return x;
    }
}
int main()
{
    lol n;
    cin >> n;
    lol a[n];
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    data c = ans(a, n);
    if (c.a==-1)
    {
      cout<<0;
    }
    else
    cout<<1;
    
    return 0;
}