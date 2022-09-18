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
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        sort(a, a + n);
        lol ans = 0;
        lol tgle = 1;
        for (lol i = n - 1; i >= 0; i--)
        {
            if (tgle)
            {
                if (a[i] % 2 == 0)
                    ans += a[i];
                tgle = 0;
            }
            else
            {
                if (a[i] % 2 != 0)
                    ans -= a[i];

                tgle = 1;
            }
        } 
        if(ans==0)
        cout<<"Tie"<<endl;
        else if(ans>0)
        cout<<"Alice"<<endl;
        else
        cout<<"Bob"<<endl;
    }

    return 0;
}