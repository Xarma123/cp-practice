#include <bits/stdc++.h>
#define lol long long
using namespace std;

int main()
{
    lol n;
    cin >> n;
    lol a[n];
    lol c[n+1];
    c[0]=0;
    for (lol i = 0; i < n; i++)
    {    
        cin >> a[i];
        c[i+1]=c[i]+a[i];
    }

    lol q;
    cin >> q;
    while (q--)
    {
        lol l, r;
        cin >> l >> r;
        cout<<(c[r]-c[l-1])/10<<endl;
    }

    return 0;
}