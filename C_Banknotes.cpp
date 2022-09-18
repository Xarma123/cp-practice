#include <bits/stdc++.h>
#define lol long long
using namespace std;

int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        lol n, k;
        cin >> n >> k;
        lol a[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        lol s = 0;
        lol c = k + 1;
        for (lol i = 0; i < n - 1; i++)
        {
            if (c * pow(10ll, a[i]) < pow(10ll, a[i + 1]))
            {
                s += c * pow(10ll, a[i]);
                c = 0;
            }
            else
            {
                s += (pow(10ll, a[i + 1]) / (pow(10ll, a[i])) - 1) * ((pow(10ll, a[i])));
                c -= (pow(10ll, a[i + 1]) / (pow(10ll, a[i])) - 1);
            }
        }

        s += c * (pow(10ll, a[n - 1]));

        cout << s << endl;
    }

    return 0;
}