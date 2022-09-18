#include <bits/stdc++.h>
using namespace std;
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        lol n;
        string str;
        cin >> n;
        cin >> str;

        lol one = 0;
        lol two = 0;
        lol flag = 1;
        for (auto c : str)
        {
            if (c == '1')
                one++;
            else
                two++;
        }
        if (two == 0)
        {
            cout << "YES" << endl;
            for (lol i = 1; i <= n * n; i++)
            {
                if (i % (n + 1) == 1)
                    cout << 'X';
                else
                    cout << '=';
                if (i % n == 0)
                    cout << endl;
            }
        }
        else if (two > 2)
        {
            cout << "YES" << endl;
            char k[n][n] = {'\0'};

            for (lol i = 0; i < n; i++) {
                for (lol j = 0; j < n; j++) {
                        k[i][j] = '\0';
                }
        }
            for (lol i = 0; i < n; i++)
            {
                flag = 1;
                for (lol j = 0; j < n - 1; j++)
                {
                    if (k[i][j] != '+' && k[i][j] != '=' && k[i][j] != '-')
                    {
                        if (i == j)
                            k[i][j] = 'X';
                        else if (str[i] == '1')
                        {
                            if (str[j] == '2')
                            {
                                k[i][j] = '+';
                                k[j][i] = '-';
                            }
                            else
                            {
                                k[i][j] = '=';
                                k[j][i] = '=';
                            }
                        }
                        else
                        {
                           
                            if (str[j] == '1')
                            {
                                k[i][j] = '-';
                                k[j][i] = '+';
                            }
                            else if (flag)
                            {
                                k[i][j] = '+';
                                k[j][i] = '-';
                                flag = 0;
                            }
                            else
                            {
                                k[i][j] = '-';
                                k[j][i] = '+';
                            }
                        }
                    }
                }
                k[n - 1][n - 1] = 'X';
            }
            for (lol i = 0; i < n; i++)
            {
                for (lol j = 0; j < n; j++)
                    cout << k[i][j];
                cout << endl;
            }
        }
        else
            cout << "NO" << endl;
    }
}