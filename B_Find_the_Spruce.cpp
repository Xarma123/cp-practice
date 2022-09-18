#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        lol n, m;
        cin >> n >> m;
        char x[n][m];
        for (lol i = 0; i < n; i++)
        {
            for (lol j = 0; j < m; j++)
            {
                cin >> x[i][j];
            }
        } 
        lol w[n][m];
        for (lol i = 0; i < n; i++)
        {
            for (lol j = 0; j < m; j++)
            {
                lol k = j;
                while (k--+1)
                {
                    if (k < 0)
                        break;
                    if (x[i][k] != '*')
                        break;
                }
                lol k2 = j;
                while (k2++)
                {
                    if (k2 >= m)
                        break;
                    if (x[i][k2] != '*')
                        break;
                } 
               w[i][j]= min(k2-j-1,j-k-1);

            }
        }

        lol ans = 0;

        for (lol i = 0; i < n; i++)
        {
            for (lol j = 0; j < m; j++)
            {
                if (x[i][j] == '*')
                {
                    ans++;
                    bool flag = true;
                    lol r = i, c = j;
                    while (1)
                    {
                        r++;
                        if (r < n)
                        {
                            if (x[r][c] == '*')
                            {
                               if(w[r][c]<r-i)
                                 flag= false;

                            }
                            else
                                flag = false;
                        }
                        else
                            break;

                        if (flag)
                            ans++;
                        else
                            break;
                    }
                }
            }
        }

        cout << ans << endl;
    }
    return 0;
}