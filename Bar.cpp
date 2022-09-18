#include <bits/stdc++.h>

#define lol long long
using namespace std;
int main()
{
    lol n;
    lol ans = 0;
    cin >> n;
    while (n--)
    {
        string a;
        cin >> a;
        if ('0' <= a[0] && a[0] <= '9')
        {
            lol x = stoi(a);
            if (x < 18)
            {
                ans++;
            }
        }
        else
        {
            if (a == "ABSINTH" || a == "BEER" || a == "BRANDY" || a == "CHAMPAGNE" || a == "GIN" || a == "RUM" || a == "SAKE" || a == "TEQUILA" || a == "VODKA" || a == "WHISKEY" || a == "WINE")
            {
               ans++;
            }
        }
    } 
    cout<<ans;

    return 0;
}