#include <bits/stdc++.h>
#define lol long long
using namespace std;
//a
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol t;
    cin >> t;
    while (t--)
    {

        lol n, m;
        cin >> n >> m;
        string a[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        bool ans = true;
        for (lol i = 0; i < n; i++)
        {
            for (lol j = 0; j < m; j++)
            {

                if (a[i][j] == '1')
                {
                    lol k = j + 1;
                    if (k < m)
                    {
                        while (a[i][k] == '1')
                        {
                            k++;
                            if (k == m)
                                break;
                        }
                    }
                    lol step = i + 1;
                    while (step < n)
                    {

                        lol c = 0;
                        for (lol q = j; q < k; q++)
                        {
                            if (a[step][q] == '1')
                                c++;
                        }
                        if (c == k - j)
                        {
                            step++;
                        }
                        else if (c == 0)
                        {
                            break;
                        }
                        else
                        {
                            ans = false;
                            break;
                        }
                    }

                    j = k - 1;
                    if (!ans)
                        break;
                }
            }
            if (!ans)
                break;
        } 

        for (lol i = n - 1; i >= 0; i--)
        {
            for (lol j = 0; j < m; j++)
            {

                if (a[i][j] == '1')
                {
                    lol k = j + 1;
                    if (k < m)
                    {
                        while (a[i][k] == '1')
                        {
                            k++;
                            if (k == m)
                                break;
                        }
                    }
                    lol step = i - 1;
                    while (step >= 0)
                    {

                        lol c = 0;
                        for (lol q = j; q < k; q++)
                        {
                            if (a[step][q] == '1')
                                c++;
                        }
                        if (c == k - j)
                        {
                            step--;
                        }
                        else if (c == 0)
                        {
                            break;
                        }
                        else
                        {
                            ans = false;
                            break;
                        }
                    }

                    j = k - 1;
                    if (!ans)
                        break;
                }
            }
            if (!ans)
                break;
        }
        if (ans)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}