#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol n;
    cin >> n;
    lol q;
    cin >> q;
    string a;
    cin >> a;
    map<char, lol> c[n + 1];
    for (lol i = 1; i <= n; i++)
    {
        for (char j = 'a'; j <= 'z'; j++)
        {  
            c[i][j] = c[i - 1][j];
        }
        c[i][a[i - 1]]++;
      
    }
    while (q--)
    {
        lol l, r;
        cin >> l >> r;
        lol ans = 0;
        for (char j = 'a'; j <= 'z'; j++)
        { 
            ans+=(c[r][j] - c[l - 1][j])*(j-'a'+1);
           
        }
        cout<<ans<<endl;
    }

    return 0;
}