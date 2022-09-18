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
        lol a[n], h = 1;
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i]; 
             if(h==-1)continue;
            if (a[i])
            {
                if (i > 0)
                {
                    if (a[i - 1])
                    {
                        h += 5;
                    }
                    else
                        h += 1;
                }
                else
                {
                    h += 1;
                }
            }
            else
            {
                if (i > 0)
                {
                    if (!a[i - 1])
                    {
                        h = -1;
                       
                    }
                }
            }
        }
        cout << h << endl;
    }

    return 0;
}