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
        lol N = n;
        n--;
        lol x = 2;
        bool f = false;
        lol c = 0;
        lol ae = 0;
        lol be = 0;
        while (n)
        {
            if (n >= x)
            {
                if (f)
                    a += x;
                else
                    b += x;
                if (x % 2 == 0)
                {
                    if (f)
                        ae += x / 2;
                    else
                        be += x / 2;
                }
                else
                {
                    if ((N - n) % 2 == 0)
                    {
                        if (f)
                            ae += x / 2;
                        else
                            be += x / 2;
                    }
                    else
                    {
                        if (f)
                            ae += x / 2 + 1;
                        else
                            be += x / 2 + 1;
                    }
                }
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
                lol x = n;
                if (x % 2 == 0)
                {
                    if (f)
                        ae += x / 2;
                    else
                        be += x / 2;
                }
                else
                {
                    if ((N - n) % 2 == 0)
                    {
                        if (f)
                            ae += x / 2;
                        else
                            be += x / 2;
                    }
                    else
                    {
                        if (f)
                            ae += x / 2 + 1;
                        else
                            be += x / 2 + 1;
                    }
                }
                n = 0;
            }
        }
        cout << a - ae << " " << ae << " " << b - be << " " << be << '\n';
    }

    return 0;
}