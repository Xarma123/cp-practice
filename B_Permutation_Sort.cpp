#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        lol n;
        cin >> n;
        lol a[n];
        bool z = true;
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
            if (a[i] != i + 1)
                z = false;
        }
        if (z)
            cout << 0 << endl;
        else if (a[0] != 1)
        { 
            if(a[n-1]!=n)
            {
                if(a[0]==n&&a[n-1]==1)
                cout<<3<<endl;
                else
                cout<<2<<endl;
            }
            else
            cout<<1<<endl;
        }
        else
            cout << 1 << endl;
    }

    return 0;
}