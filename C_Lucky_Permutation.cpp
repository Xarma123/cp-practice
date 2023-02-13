#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n;
    cin >> n;
    if (n == 1)
        cout << 1;
    else if (n == 2 || n == 3)
        cout << -1;
    else
    {
        lol p[n];
        lol i = 0, j = n - 1;
        bool f = true;
        while (j >= i)
        {
            if (j == i)
            {
                p[i] = i + 1;
                break;
            }
            if (j - i + 1 == 2 || j - i + 1 == 3)
            {
                f = false;
                break;
            }
            p[i] = i + 2;
            p[i + 1] = n - i;
            p[n - i - 1] = n - i - 1;
            p[n - i - 2] = i + 1;
            i += 2;
            j -= 2;
        }
        if (f)
        {
            for (lol i = 0; i < n; i++)
            {
                cout << p[i] << " ";
            }
        }
        else
            cout << -1;
    }

    return 0;
}