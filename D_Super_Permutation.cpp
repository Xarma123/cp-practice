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
        if (n == 1)
            cout << 1 << '\n';
        else if (n % 2)
            cout << -1 << '\n';
        else
        {
            lol l = 0, r = n - 1;
            bool f = true;
            lol s = 0;
            for (lol i = 0; i < n; i++)
            {
                lol fk;
                if (f)
                    fk = l;
                else
                    fk = r;

                if (s < fk)
                {
                    cout << fk - s << " ";
                }
                else
                {
                    cout << n - s + fk << " ";
                }
                if (f)
                    s = l, l++;
                else
                    s = r, r--;

                if (f)
                    f = false;
                else
                    f = true;
            }
            cout << '\n';
        }
    }

    return 0;
}