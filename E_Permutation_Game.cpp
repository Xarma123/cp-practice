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
        lol f = 0, in = 0, s = 0;
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
            if (a[i] != i + 1)
                f++;
            if (a[i] != n - i)
                s++;
            if ((a[i] != i + 1) && (a[i] != n - i))
                in++;
        }
        if (f <= s - in)
            cout << "First" << endl;
        else if (s < f - in)
            cout << "Second" << endl;
        else
            cout << "Tie" << endl;
    }

    return 0;
}