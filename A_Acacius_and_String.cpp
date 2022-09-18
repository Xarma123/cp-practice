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
        string s;
        cin >> s;
        string c = "abacaba";
        lol al = 0;
        bool ans = false;
        string q = s;
        for (lol i = 0; i + 6 < n; i++)
        {
            if (al > 1)
                break;
            string a = s.substr(i, 7);
            bool f = true;
            if (a == c)
                al++;
            for (lol j = 0; j < 7; j++)
            {
                if (a[j] != c[j] && a[j] != '?')
                {
                    f = false;
                    break;
                }
            }
            if (f)
            {
                string x = s;
                for (lol j = i; j < i + 7; j++)
                {
                    x[j] = c[j - i];
                }
                lol cou = 0;
                for (lol j = 0; j + 6 < n; j++)
                {
                    string b = x.substr(j, 7);
                    if (b == c)
                    {
                        cou++;
                    }
                }
                if (cou == 1)
                {
                    q = x;
                    ans = true;
                    break;
                }
            }
        }
        if (al == 1)
        {
            cout << "Yes" << endl;
            for (lol i = 0; i < n; i++)
            {
                if (q[i] != '?')
                    cout << q[i];
                else
                    cout << 'z';
            }
            cout << endl;
        }
        else if (al > 1)
            cout << "No" << endl;
        else if (ans)
        {
            cout << "Yes" << endl;
            for (lol i = 0; i < n; i++)
            {
                if (q[i] != '?')
                    cout << q[i];
                else
                    cout << 'z';
            }
            cout << endl;
        }
        else
            cout << "No" << endl;
    }

    return 0;
}