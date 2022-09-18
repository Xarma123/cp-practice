#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol n;
    cin >> n;
    lol s[n];
    lol c[n];
    for (lol i = 0; i < 2 * n; i++)
    {
        if (i < n)
            cin >> s[i];
        else
            cin >> c[i - n];
    }
    lol ans=LONG_LONG_MAX;
    for (lol j = 1; j < n - 1; j++)
    {
        lol cb = -1;
        for (lol i = 0; i < j; i++)
        {
            if (s[i] < s[j])
            {
                if (cb == -1)
                    cb = c[i];
                cb = min(cb, c[i]);
            }
        }
        lol ca = -1;
        for (lol k = j + 1; k < n; k++)
        {
            if (s[k] > s[j])
            {
                if (ca == -1)
                    ca = c[k];
                ca = min(ca, c[k]);
            }
        } 
        if(ca!=-1&&cb!=-1)
         ans=min(ans,(ca+cb+c[j]));
    }
    if(ans==LONG_LONG_MAX)
    cout<<-1;
    else
    cout<<ans;

    return 0;
}