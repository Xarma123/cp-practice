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
        vector<lol> divisor;
        for (lol i = 1; i <= sqrt(n); i++)
        {
            if (n % i == 0)
            {

                if (n / i == i)
                    divisor.push_back(i));
                else
                {   divisor.push_back(i));
                     divisor.push_back(n/i));
                }
            }
        }
        sort(divisor.begin(), divisor.end());
        lol i;
        for (lol i = divisor.size() - 1; i >= 0; i--)
        {
            if ((n / divisor[i]) % 2 == 0)
            {
                n -= divisor[i];
                break;
            }
        }

        return 0;
    }