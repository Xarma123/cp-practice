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
        lol ans = -1;
        for (lol i = 0; i < n; i++)
        {
            lol t;
            cin >> t;
            if (i == 0)
                ans = t;
            else
                ans = ans & t;
        } 
        cout<<ans<<endl;
    }

    return 0;
}