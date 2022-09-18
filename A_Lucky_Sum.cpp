#include <bits/stdc++.h>
#define lol long long
using namespace std;
lol next(string n)
{

    lol s = n.size();
    lol mn = LONG_LONG_MAX;
    lol ans = -1;

    for (lol i = 0; i < pow(2, s); i++)
    {
        string a = "";
        lol j = 0;

        while (j < s)
        {
            if (i & (1 << j))
            {
                a = a + "7";
            }
            else
            {
                a = a + "4";
            }
            j++;
        }

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
    if (ans == -1)
    {
        string a = "";
        for (lol i = 0; i <= s; i++)
        {
            a = a + "4";
        }
        return stoll(a);
    }
    else
        return ans;
}
int main()
{
    lol l, r;
    cin >> l >> r;
    lol ans = 0;
    for (lol i = l; i <= r; i++)
    {
        lol x = next(to_string(i));

        if (x > r)
        {
            ans += (r - i + 1) * x;
            break;
        }
        else
        {
            ans += (x - i + 1) * x;
            i = x;
        }
    }
    cout << ans;

    return 0; 
    
}
