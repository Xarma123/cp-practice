#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol t;
    cin >> t;
    while (t--)
    {
        string a[10];
        for (lol i = 0; i < 10; i++)
        {
            cin >> a[i];
        }
        lol ans = 0;
        for (lol i = 0; i < 10; i++)
        {
            for (lol j = 0; j < 10; j++)
            {
                if (a[i][j] == 'X')
                {
                    if (i == 0 || i == 9)
                    {
                        if (a[i][j] == 'X')
                            ans++;
                    }
                    else if (i == 1 || i == 8)
                    {
                        if (a[i][j] == 'X')
                        {
                            if (j == 0 || j == 9)
                            {
                                ans++;
                            }
                            else
                            {
                                ans += 2;
                            }
                        }
                    }
                    else if (i == 2 || i == 7)
                    {
                        if (j == 0 || j == 9)
                        {
                            ans++;
                        }
                        else if (j == 1 || j == 8)
                        {
                            ans += 2;
                        }
                        else
                            ans += 3;
                    }
                    else if (i == 3 || i == 6)
                    {
                        if (j == 0 || j == 9)
                        {
                            ans++;
                        }
                        else if (j == 1 || j == 8)
                        {
                            ans += 2;
                        }
                        else if (j == 2 || j == 7)
                            ans += 3;
                        else
                            ans += 4;
                    }
                    else if (i == 4 || i == 5)
                    {
                        if (j == 0 || j == 9)
                        {
                            ans++;
                        }
                        else if (j == 1 || j == 8)
                        {
                            ans += 2;
                        }
                        else if (j == 2 || j == 7)
                            ans += 3;
                        else if (j == 3 || j == 6)
                            ans += 4;
                        else
                            ans += 5;
                    }
                }
            }
        }
        cout << ans << '\n';
    }
}