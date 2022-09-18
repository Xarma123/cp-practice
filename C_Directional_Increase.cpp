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
        lol a[n];
        bool z = true;
        lol l = -1;
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
            if (a[i] != 0)
                l = i;
        }
        if (n == 1)
        {
            if (a[0] == 0)
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
        }
        else if (l == -1)
        {
            cout << "Yes" << endl;
        }
        else
        {

            bool ans = true;
            if (a[0] < 1)
                ans = false;
            if (a[n - 1] > 0)
                ans = false;
            lol lena = 0;
            for (lol i = 0; i < n; i++)
            {
                if (a[i] > 0)
                {
                    lena += a[i];
                }
                else if (a[i] < 0)
                {
                    if (lena < -a[i])
                    {
                        ans = false;
                        break;
                    }
                    else
                        lena -= -a[i];
                }

                if (lena == 0 && l == i)
                {
                    break;
                }
                if (lena == 0 && l != i)
                    ans = false;
            }

            if (ans && lena == 0)
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
        }
    }

    return 0;
}