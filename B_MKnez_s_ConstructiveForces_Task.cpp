#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol t;
    cin >> t;
    while (t--)
    {
        lol n;
        cin >> n;
        if (n == 3)
            cout << "NO" << endl;
        else
        {
            cout << "YES" << endl;
            if (n % 2 == 0)
            {
                lol g = 1;
                for (lol i = 0; i < n; i++)
                {
                    cout << g << " ";
                    g = -g;
                }
                cout << endl;
            }
            else
            {
                lol a = -(n / 2 - 1);
                lol b = 1 - a;
                for (lol i = 0; i < n; i++)
                {
                    if (i % 2 == 0)
                        cout << a << " ";
                    else
                        cout << b << ' ';
                }
                cout << endl;
            }
        }
    }

    return 0;
}