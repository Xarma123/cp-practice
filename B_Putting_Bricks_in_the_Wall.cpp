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
        lol g[n][n];
        bool wall[2];
        for (lol i = 0; i < n; i++)
        {
            for (lol j = 0; j < n; j++)
            {
                char s;
                if ((i == 0 && j == 0) || (i == n - 1 && j == n - 1))
                {
                    cin >> s;
                    g[i][j] = 0;
                }
                else
                    cin >> g[i][j];
            }
        }
        if (g[1][0] == g[0][1] && g[n - 1][n - 2] == g[n - 2][n - 1] && g[1][0] != g[n - 1][n - 2])
        {
            cout << 0 << endl;
            continue;
        }
        else
        {
            lol ans = 0;
            bool fh0 = true, fh1 = true;
            bool fv0 = true, fv1 = true;
            for (lol i = 1; i < n - 1; i++)
            {
                lol t = 0;
                t = 0;
                for (lol j = 0; j < n; j++)
                {
                    t += g[i][j];
                }
                if (t == 0)
                    fh0 = false;
                if (t == n)
                    fh1 = false;
            }
            for (lol i = 1; i < n - 1; i++)
            {
                lol t = 0;
                t = 0;
                for (lol j = 0; j < n; j++)
                {
                    t += g[j][i];
                }
                if (t == 0)
                    fv0 = false;
                if (t == n)
                    fv1 = false;
            }

            if ((fh1 == false && fh0 == false) || (fv1 == false && fv0 == false))
                cout << 0 << endl;
            else
            {
                if (fh0 == false || fv0 == false)
                {
                    if (g[1][0] + g[0][1] == 2)
                        cout << 0 << endl;
                    else if (g[n - 1][n - 2] + g[n - 2][n - 1] == 2)
                        cout << 0 << endl;
                    else if (g[1][0] + g[0][1] == 1)
                    {
                        cout << 1 << endl;
                        if (g[0][1] == 0)
                            cout << 0 << " " << 1 << endl;
                        else
                            cout << 1 << " " << 0 << endl;
                    }
                    else if (g[n - 1][n - 2] + g[n - 2][n - 1] == 1)
                    {
                        cout << 1 << endl;
                        if (g[n - 1][n - 2] == 0)
                            cout << n - 1 << " " << n - 2 << endl;
                        else
                            cout << n - 2 << " " << n - 1 << endl;
                    }
                    else
                    {
                        cout << 2 << endl;
                        cout << 0 << " " << 1 << endl;
                        cout << 1 << " " << 0 << endl;
                    }
                }
                else if (fh1 == false || fv1 == false)
                {
                    if (g[1][0] + g[0][1] == 0)
                        cout << 0 << endl;
                    else if (g[n - 1][n - 2] + g[n - 2][n - 1] == 0)
                        cout << 0 << endl;
                    else if (g[1][0] + g[0][1] == 1)
                    {
                        cout << 1 << endl;
                        if (g[0][1] == 1)
                            cout << 0 << " " << 1 << endl;
                        else
                            cout << 1 << " " << 0 << endl;
                    }
                    else if (g[n - 1][n - 2] + g[n - 2][n - 1] == 1)
                    {
                        cout << 1 << endl;
                        if (g[n - 1][n - 2] == 1)
                            cout << n - 1 << " " << n - 2 << endl;
                        else
                            cout << n - 2 << " " << n - 1 << endl;
                    }
                    else
                    {
                        cout << 2 << endl;
                        cout << 0 << " " << 1 << endl;
                        cout << 1 << " " << 0 << endl;
                    }
                }
                else
                {
                    if (g[0][1] + g[1][0] == 2)
                    {
                        if (g[n - 1][n - 2] + g[n - 2][n - 1] == 0)
                            cout << 0 << endl;
                        else if (g[n - 1][n - 2] + g[n - 2][n - 1] == 1)
                        {
                            cout << 1 << endl;
                            if (g[n - 1][n - 2] == 1)
                                cout << n - 1 << " " << n - 2 << endl;
                            else
                                cout << n - 2 << " " << n - 1 << endl;
                        }
                        else if (g[n - 1][n - 2] + g[n - 2][n - 1] == 2)
                        {
                            cout << 2 << endl;
                            cout << n - 1 << " " << n - 2 << endl;
                            cout << n - 2 << " " << n - 1 << endl;
                        }
                    }
                    else if (g[0][1] + g[1][0] == 0)
                    {
                        if (g[n - 1][n - 2] + g[n - 2][n - 1] == 2)
                            cout << 0 << endl;
                        else if (g[n - 1][n - 2] + g[n - 2][n - 1] == 1)
                        {
                            cout << 1 << endl;
                            if (g[n - 1][n - 2] == 0)
                                cout << n - 1 << " " << n - 2 << endl;
                            else
                                cout << n - 2 << " " << n - 1 << endl;
                        }
                        else if (g[n - 1][n - 2] + g[n - 2][n - 1] == 0)
                        {
                            cout << 2 << endl;
                            cout << n - 1 << " " << n - 2 << endl;
                            cout << n - 2 << " " << n - 1 << endl;
                        }
                    }
                    else
                    {
                        if (g[n - 1][n - 2] + g[n - 2][n - 1] == 2)
                        {
                            cout << 1 << endl;
                            if (g[0][1] == 1)
                                cout << 0 << " " << 1 << endl;
                            else
                                cout << 1 << " " << 0 << endl;
                        }
                        else if (g[n - 1][n - 2] + g[n - 2][n - 1] == 0)
                        {
                            cout << 1 << endl;
                            if (g[0][1] == 0)
                                cout << 0 << " " << 1 << endl;
                            else
                                cout << 1 << " " << 0 << endl;
                        }
                        else
                        {

                            cout << 2 << endl;
                            if (g[0][1] == 0)
                                cout << 0 << " " << 1 << endl;
                            else
                                cout << 1 << " " << 0 << endl;
                            if (g[n - 1][n - 2] == 1)
                                cout << n - 1 << " " << n - 2 << endl;
                            else
                                cout << n - 2 << " " << n - 1 << endl;
                        }
                    }
                }
            }
        }

        return 0;
    }
}