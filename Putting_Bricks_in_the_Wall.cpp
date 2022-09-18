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
        char g[n][n];
        bool wall[2];
        for (lol i = 0; i < n; i++)
        {
            for (lol j = 0; j < n; j++)
            {
                cin >> g[i][j];
            }
        }
        if (g[1][0] == g[0][1] && g[n - 1][n - 2] == g[n - 2][n - 1] && g[1][0] != g[n - 1][n - 2])
        { 
            cout<<0<<endl;
            continue;
        }
        else
        {
            for (lol i = 0; i < n; i++)
            {
               for (lol j = 0; j < n; j++)
               {
                   
               }
               
            }
            
        }
    }

    return 0;
}