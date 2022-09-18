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
        string a;
        cin >> a;
        lol i;
        for (i = n - (n / 2) - 1; i >= 0; i--)
        {
            if (a[i] == '0')
                break;
        }
        if (i >= 0)
            cout << i + 1 << " " << n << " " << i + 2 << " " << n << endl;
        else
        {
            for (i = n / 2; i < a.size(); i++)
            {
                if (a[i] == '0')
                {
                    cout << 1 << ' ' << i + 1 << " " << 1 << " " << i << endl;
                    break;
                }
            }
            if (i == a.size())
                cout << 1 << " " << n - 1 << " " << 2 << " " << n << endl;
        }
    }

    return 0;
}