#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol t;
    cin >> t;
    while (t--)
    {
        lol n;
        cin >> n;
        string s;
        cin >> s;
        bool a = false, b = false;
        for (lol i = 1; i <= n; i++)
        {
            for (lol j = 1; j <= n; j++)
            {
                lol ca = 0, cb = 0;
                lol csa = 0, csb = 0;
                lol k = 0;
                for (auto e : s)
                {
                    if (e == 'A')
                        ca++;
                    else
                        cb++;
                    if (ca == i)
                    {
                        csa++;
                        ca = 0;
                        cb = 0;
                    }
                    else if (cb == i)
                    {
                        csb++;
                        cb = 0;
                        ca = 0;
                    }
                    if (csa == j)
                        break;
                    if (csb == j)
                        break;
                    k++;
                }
                if (k == n - 1)
                {
                    if (csa == j)
                        a = true;
                    else if (csb == j)
                        b = true;
                }
            }
        }
        if (a && b)
            cout << "?\n";
        else if (a)
            cout << "A\n";
        else if (b)
            cout << "B\n";
    }

    return 0;
}
