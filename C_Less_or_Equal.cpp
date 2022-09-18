#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol n, k;
    cin >> n >> k;
    lol a[n];
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n);
    if (k < n)
    {
        if (k == 0)
        {       
            if(a[0]-1>=1&&a[0]-1<=1e9)
            cout<<a[0]-1;
            else
            cout<<-1;
        }
        else
        {
            if (a[k - 1] != a[k])
                cout << a[k - 1];
            else
                cout << -1;
        }
    }
    else
    {
        cout << a[n - 1];
    }

    return 0;
}