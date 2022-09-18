#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol n;
    cin >> n;
    lol B[4];
    lol W[4];
    for (lol i = 0; i < 4; i++)
    {
        lol b = 0;
        lol w = 0;
        string a;
        lol tggle = 1;
        for (lol j = 0; j < n; j++)
        {
            cin >> a;
            if (tggle)
            {
                lol tgle = 1;
                for (lol k = 0; k < a.size(); k++)
                {
                    if (tgle)
                    {
                        if (a[k] == '0')
                            w++;
                        else
                            b++;
                        tgle = 1 - tgle;
                    }
                    else
                    {
                        if (a[k] == '0')
                            b++;
                        else
                            w++;
                        tgle = 1 - tgle;
                    }
                }
                tggle = 1 - tggle;
            }
            else
            {
                lol tgle = 1;
                for (lol k = 0; k < a.size(); k++)
                {
                    if (tgle)
                    {
                        if (a[k] == '0')
                            b++;
                        else
                            w++;
                        tgle = 1 - tgle;
                    }
                    else
                    {
                        if (a[k] == '0')
                            w++;
                        else
                            b++;
                        tgle = 1 - tgle;
                    }
                }
                tggle=1-tggle;
            }
        }
        B[i] = b;
        W[i] = w;
    }

    
    lol ans = LONG_LONG_MAX;
    for (lol i = 0; i < 4; i++)
    {

        for (lol j = i + 1; j < 4; j++)
        {
            lol c = 0;
            c += B[i] + B[j];
            for (lol k = 0; k < 4; k++)
            {
                if (k != i && k != j)
                {
                    c += W[k];
                }
            } 
            ans=min(ans,c);
        }
    } 
    cout<<ans;

    return 0;
}