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
        lol a = 1, b = 0;
        n--;
        lol x = 2;
        bool f = false;
        lol c = 0;
        while (n)
        {
            if (n >= x)
            {
                if (f)
                    a += x;
                else
                    b += x;
                n -= x;
                x++;
                c++;
                if (c == 2)
                {
                    c = 0;
                    if (f)
                        f = false;
                    else
                        f = true;
                }
            }
            else
            {
                if (f)
                    a += n;
                else
                    b += n;
                n = 0;
            }
        }
        cout << a << " " << b << '\n';
    }

    return 0;
}