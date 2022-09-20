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
        lol n, p;
        cin >> n >> p;
        lol c = 0;
        for (lol i = 1; i <= n && c < 2 * 1ll * n + p; i++)
        {
            for (lol j = i + 1; j <= n && c < 2 * 1ll * n + p; j++)
            {
                cout << i << " " << j << endl;
                c++;
            }
        } 
        
    }

    return 0;
}