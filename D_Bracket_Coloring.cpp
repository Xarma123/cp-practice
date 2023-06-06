#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        lol n;
        cin >> n;
        string s;
        cin >> s;
        lol op = 0;
        for (lol i = 0; i < n; i++)
        {
            if (s[i] == '(')
                op++;
        }

        if (op != n - op)
            cout << -1 << '\n';
        else
        {
            lol c = 0;
            lol i;
            for (i = 0; i < n; i++)
            {
                if (s[i] == '(')
                    c++;
                else
                    c--;
                if (c < 0)
                    break;
            }
            if (i == n)
            {
                cout << 1 << '\n';
                for (lol i = 0; i < n; i++)
                {
                    cout << 1 << " ";
                }
                cout << '\n';
            }
            else
            {
                c = 0;
                for (i = n - 1; i >= 0; i--)
                {
                    if (s[i] == '(')
                        c++;
                    else
                        c--;
                    if (c < 0)
                        break;
                }
                if (i == -1)
                {
                    cout << 1 << '\n';
                    for (lol i = 0; i < n; i++)
                    {
                        cout << 1 << " ";
                    }
                    cout << '\n';
                }
                else
                {
                    c = 0;
                    cout << 2 << '\n';
                    for (i = 0; i < n; i++)
                    {
                        if (c < 0 && s[i] == '(')
                            cout << 2 << " ";
                        else if (c >= 0 && s[i] == '(')
                            cout << 1 << " ";

                        if (s[i] == '(')
                            c++;
                        else
                            c--;
                        if (c < 0 && s[i] == ')')
                        {
                            cout << 2 << " ";
                        }
                        else if (c >= 0 && s[i] == ')')
                            cout << 1 << " ";
                    }
                    cout << '\n';
                }
            }
        }
    }
}
// ( (  )  ) ) )