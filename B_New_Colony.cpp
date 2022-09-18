#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        lol n, k;
        cin >> n >> k;
        lol h[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> h[i];
        }
        lol i;
        while (k--)
        {

            for (i = 0; i < n - 1; i++)
            {
                if (h[i] < h[i + 1])
                {
                    h[i]++;
                    break;
                }
            }
            if (i == n - 1)
            {
                i = -2;
                break;
            }
        } 
        cout<<i+1<<endl;
    }

    return 0;
}