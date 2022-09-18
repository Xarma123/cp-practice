#include <bits/stdc++.h>
#define lol long long
using namespace std;
lol GetLeftMostSetBit(lol n)
{
    lol pos = 0;

    while (n > 0)
    {
        pos++;
        n >>= 1;
    }

    return pos;
}
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        lol l, r;
        cin >> l >> r;
        l--;
        lol ans = INT_MAX;
        lol ll = GetLeftMostSetBit(l);
        lol lr = GetLeftMostSetBit(r);
        lol curr = 0, curl = 0;
        lol totalRep, mod;
        lol nearestPow;
        lol totalSetBitCount = 0;
        lol addRemaining = 0;
        for (lol i = 1; i <= lr; ++i)
        {
            curr = 0;
            curl = 0;
            nearestPow = pow(2, i);
            if (nearestPow > r)
            {
                lol lastPow = pow(2, i - 1);
                mod = r % lastPow;
                curr += mod + 1;
            }
            else
            {
                if (i == 1 && r % 2 == 1)
                {
                    totalRep = (r + 1) / nearestPow;
                    mod = nearestPow % 2;
                    addRemaining = 0;
                }
                else
                {
                    totalRep = r / nearestPow;
                    mod = r % nearestPow;

                    if (mod >= (nearestPow / 2))
                    {
                        addRemaining = mod - (nearestPow / 2) + 1;
                    }
                    else
                    {
                        addRemaining = 0;
                    }
                }

                curr = totalRep * (nearestPow / 2) + addRemaining;
            }
            if (i <= ll)
            {
                if (nearestPow > r)
                {
                    lol lastPow = pow(2, i - 1);
                    mod = l % lastPow;
                    curl += mod + 1;
                }
                else
                {
                    if (i == 1 && l % 2 == 1)
                    {
                        totalRep = (l + 1) / nearestPow;
                        mod = nearestPow % 2;
                        addRemaining = 0;
                    }
                    else
                    {
                        totalRep = l / nearestPow;
                        mod = l % nearestPow;

                        if (mod >= (nearestPow / 2))
                        {
                            addRemaining = mod - (nearestPow / 2) + 1;
                        }
                        else
                        {
                            addRemaining = 0;
                        }
                    }

                    curl = totalRep * (nearestPow / 2) + addRemaining;
                }
            }
            ans = min(ans, (r - l) - (curr - curl));

           
        }

        cout << ans << endl;
    }

    return 0;
}