#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol n;
    cin >> n;
    lol a[n];
    bool ans = true;
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    string s;
    cin >> s;
    for (lol i = 0; i < n - 1; i++)
    {
        if (s[i] == '1')
        {
            lol mn = a[i], mx = a[i];
            lol j = i + 1;
            if (j < n - 1)
            {
                while (s[j] == '1')
                {
                    mn = min(mn, a[j]);
                    mx = max(mx, a[j]);
                    j++;
                    if (j == n - 1)
                        break;
                }
            }
            mn = min(mn, a[j]);
            mx = max(mx, a[j]);
            if (mn != i + 1 || mx != j + 1)
                ans = false;
            i = j;
        }
    }

    for (lol i = 0; i < n; i++)
    {
        if (a[i] != i + 1)
        {
            if (i < n - 1)
            {
                if (s[i] == '0')
                {
                    if (i - 1 >= 0)
                    {

                        if (s[i - 1] != '1')
                            ans = false;
                    }
                    else
                        ans = false;
                }
            }
        }
    }
    if (ans)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}