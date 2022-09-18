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
        lol se = 0, so = 0;
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
            if (i%2==0)
            {
                so += a[i];
            }
            else
                se += a[i];
        }
        if (se <= so)
        {

            for (lol i = 0; i < n; i++)
            {
                if (i%2==0)
                {
                    cout << a[i] << " ";
                }
                else
                    cout << 1 << " ";
            }
        }
        else
        {
            for (lol i = 0; i < n; i++)
            {
                if (i%2==0)
                {
                    cout << 1 << " ";
                }
                else
                    cout << a[i] << " ";
            }
        } 
        cout<<endl;
    }

    return 0;
}