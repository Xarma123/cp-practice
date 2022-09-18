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
        string a[2];
        cin >> a[0] >> a[1];
        lol ans = 0;
        for (lol i = 0; i < n; i++)
        {
            if (a[0][i] != a[1][i])
                ans += 2;
            else
            {
                if (a[0][i] == '0')
                {
                    if (i + 1 < n)
                    {
                        if (a[0][i + 1] == '1'&&a[1][i + 1] == '1')
                        {
                            ans += 2;
                            i++;
                        }
                        else
                        ans++;
                    }
                    else
                    ans++;
                }
                else
                {
                    if (i + 1 < n)
                    {
                        if (a[0][i + 1] == '0'&&a[1][i + 1] == '0')
                        {
                            ans += 2;
                            i++;
                        }
                       
                    }
                }
            }
        } 
        cout<<ans<<endl;
    }

    return 0;
}