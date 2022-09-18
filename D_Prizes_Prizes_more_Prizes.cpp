#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n;
    cin >> n;
    lol p[n];
    for (lol i = 0; i < n; i++)
    {
        cin >> p[i];
    }
    lol g[5];
    lol c[5];
    for (lol i = 0; i < 5; i++)
    {
        cin >> g[i];
        c[i] = 0;
    }
    lol pg = 0;
    for (lol i = 0; i < n; i++)
    {
        pg += p[i];
        for (lol j = 4; j >= 0; j--)
        {
            if (pg >= g[j])
            {
                c[j] += (pg / g[j]);
                pg -= (pg / g[j]) * g[j];
            }
        }
    }
    for (lol i = 0; i < 5; i++)
    {
        cout << c[i] << " ";
    }
    cout << endl;
    cout << pg << endl;

    return 0;
}