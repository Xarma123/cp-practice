#include <bits/stdc++.h>
#define lol long long
using namespace std;

int main()
{
    lol t;
    cin >> t;
    bool prime[(long long)1e6 + 1];
    memset(prime, true, sizeof(prime));
    for (lol p = 2; p * p <= (long long)1e6; p++)
    {

        if (prime[p] == true)
        {

            for (lol i = p * p; i <= (long long)1e6; i += p)
                prime[i] = false;
        }
    }

    while (t--)
    {
        lol d;
        cin >> d;
        lol f;
        for (lol i = 1 + d; i <= 1e6; i++)
        {
            if (prime[i] == true)
            {
                f = i;
                break;
            }
        } 
        lol s;
        for (lol i = f + d; i <= 1e6; i++)
        {
            if (prime[i] == true)
            {
                s = i;
                break;
            }
        }  
        cout<<f*1ll*s<<endl;

    }

    return 0;
}