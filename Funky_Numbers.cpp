#include <bits/stdc++.h>
#define lol long long
using namespace std;

using namespace std;

lol n;
lol cal(lol ans)
{
    return ans * (ans + 1) / 2;
}

int main()
{
    cin >> n;
    lol flag = 0;
    for (lol i = 1; i <= sqrt(2 * n) + 1; i++)
    {
        lol sum = n - cal(i);
        lol l = i, r = sqrt(2 * n) + 1;
        lol mid;
        while (l < r)
        {
            mid = (l + r) / 2;
            if (cal(mid) == sum)
            {
                flag = 1;
                break;
            }
            if (cal(mid) < sum)
                l = mid;



                
            else
                r = mid;
            if (r - l == 1)
            {
                if (cal(r) == sum || cal(l) == sum)
                {
                    flag = 1;
                    break;
                }
                else
                    break;
            }
        }
        if (flag)
            break;
    }
    if (flag)
        prlolf("YES");
    else
        prlolf("NO");
}