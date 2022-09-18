#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    string n;
    cin >> n;
    lol s = n.size();
    lol mn = LONG_LONG_MAX;
    lol ans = -1;

    for (lol i = 0; i < pow(2, s); i++)
    {
        string a = "";
        lol j = 0;
        lol c1 = 0, c2 = 0;
        while (j < s)
        {
            if (i & (1 << j))
            {
                a = a + "7";
                c1++;
            }
            else
            {
                a = a + "4";
                c2++;
            }
            j++;
        }
        if (c1 == c2)
        {
            lol one = stoll(a);
            lol two = stoll(n);

            if (one >= two)
            {

                if (one - two < mn)
                {
                    mn = one - two;
                    ans = one;
                }
            }
        }
    }
    if (ans == -1)
    {
        if (s % 2 == 0)
        {
            s += 2;
        }
        else
        {
            s++;
        }
        for (lol i = 1; i <= s; i++)
        {
            if (i <= s / 2)
            {
                cout << 4;
            }
            else
                cout << 7;
        }
    }
    else
        cout << ans;

    return 0;
}