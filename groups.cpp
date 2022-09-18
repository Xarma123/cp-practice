#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
void solve()
{
    lol n;
    cin >> n;
    lol failed = 6;
    lol flag = 0;
    lol arr[n][5];
    for (lol i = 0; i < n; i++)
    {
        for (lol j = 0; j < 5; j++)
        {
            cin >> arr[i][j];
        }
    }
    lol sum[5];
    for (lol i = 0; i < 5; i++)
    {
        sum[i] = 0;
        for (lol j = 0; j < n; j++)
        {
            sum[i] += arr[j][i];
        }
    }
    for (lol i = 0; i < 5; i++)
    {
        if (sum[i] < n / 2)
            continue;
        else
        {
            for (lol j = i + 1; j < 5; j++)
            {
                flag = 0;
                if (sum[j] < n / 2)
                    continue;
                else
                {
                    for (lol s = 0; s < n; s++)
                    {
                        if (arr[s][i] == 1)
                            continue;
                        else if (arr[s][j] == 1)
                            continue;
                        else
                        {
                            flag = 1;
                            break;
                        }
                    }
                    if (flag == 1)
                        failed = 1;
                    else
                        failed = 0;
                }
                if (failed == 0)
                {
                    cout << "YES" << endl;
                    return;
                }
            }
        }
    }
    if (failed != 0)
        cout << "NO" << endl;
}
int main()
{
    lol t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
}