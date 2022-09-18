#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        lol n, a, b;
        cin >> n >> a >> b;
        string s;
        cin >> s;
        if (b >= 0)
        {
            cout << (a + b) * n << endl;
        }
        else
        {
            lol c = 0;
            for (lol i = 0; i < n; i++)
            {
                c++;
                if (i + 1 < n)
                {
                    while (s[i] == s[i + 1])
                    {

                        i++;
                        if (i == n - 1)
                            break;
                    }
                }
            }
            lol ans = 0;
            while (c > 2)
            {
                ans++;
                c -= 2;
            }
            ans += c;

            cout << ans * b + a * n << endl;
        }
    }

    return 0;
}