#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol k;
    cin >> k;
    lol a[10];
    lol s = 1;
    for (lol i = 0; i < 10; i++)
    {
        a[i] = 1;
    }
    string ans = "codeforces";
    if (s >= k)
    {
        cout << ans << endl;
    }
    else
    {
        while (s < k)
        {
            for (lol i = 0; i < 10; i++)
            {
                s = s / a[i];
                a[i]++;
                s =s*1ll*a[i];
                if (s >= k)
                    break;
            }
        } 
        for (lol i = 0; i < 10; i++)
        {
           while(a[i]--)
           cout<<ans[i];
        }
        
    }

    return 0;
}