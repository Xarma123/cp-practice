#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol h, w;
    cin >> h >> w;
    lol r[h];
    lol c[w];
    char m[h][w];
    for (lol i = 0; i < h; i++)
    {
        for (lol j = 0; j < w; j++)
        {
            m[i][j] = 'n';
        }
    }

    for (lol i = 0; i < h; i++)
    {
        cin >> r[i];
    }
    for (lol i = 0; i < w; i++)
    {
        cin >> c[i];
    }
    bool ans = true;
    for (lol i = 0; i < h; i++)
    {
        lol j;
        for (j = 0; j < r[i]; j++)
        {
            m[i][j] = 'B';
        }
        if (r[i] < w)
            m[i][r[i]] = 'x';
    }

    for (lol j = 0; j < w; j++)
    {
        lol i;
        for (i = 0; i < c[j]; i++)
        {
            if (m[i][j] == 'x')
            {
                ans = false;

                break;
            }
            m[i][j] = 'B';
        }
        if (c[j] < h)
        {
            if (m[c[j]][j] == 'B')
            {
                ans = false;

                break;
            }
            m[c[j]][j] = 'x';
        }
    }
    if (!ans)
        cout << 0 << endl;
    else
    {
        lol q = 0;
        for (lol i = 0; i < h; i++)
        {
            for (lol j = 0; j < w; j++)
            {
                if (m[i][j] == 'n')
                    q++;
            }
        } 
        lol k = 1;
        for (lol j = 0; j <q; j++)
        {
           k= (k*1ll*2)%(1000000007);
        } 
        cout<<k;
        
    }

    return 0;
}