#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol n;
    cin >> n;
    lol a[n];

    lol nod = 0;
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] % 2 != 0)
        {
            nod++;
        }
    }
    if (nod == 0)
        cout << 0 << endl;
    else
    {
        for (lol i = 29; i >= 0; i--)
        {
            bool f = false;
            for (lol j = 0; j < n; j++)
            {

                if ((a[j] >> i) & 1)
                {
                    f = true;
                }
            }
            if (!f)
            {
                for (lol j = 0; j < n; j++)
                {   
                    if ((a[j] >> i) > 0)
                        a[j] = 0;
                }
            }
        }
        lol f = -1, e = -1, ans = 0;
        
        
        for (lol i = 0; i < n; i++)
        {
            if (a[i] != 0)
            {
                if (f == -1)
                    f = i;
            }
            else
            {
                if (f != -1)
                {
                    e = i - 1;
                    e = e - f + 1;
                    ans = max(ans, e);
                    f = -1;
                    e = -1;
                }
            }
        } 
        if(f!=-1)
        {
            if(e==-1)
            f= n-f;
            ans=max(ans,f);
        } 
        cout<<ans;
    }

    return 0;
}