#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n, m;
    cin >> n >> m;
    bool p[51];
    memset(p, true, sizeof(p));
    for (lol i = 2; i <= 50; i++)
    {
        if (p[i])
        {
            for (lol j = i * i; j <= 50; j += i)
            {
                p[j] = false;
            }
        }
    }
    if (p[n] && p[m])
    {
        lol j;
        for (j = n + 1; j <= 50; j++)
        {
            if (p[j])
            {
                break;
            }
        }
        if (j == m)
            cout << "YES";
        else
            cout << "NO";
    }
    else
        cout << "NO";

    return 0;
}