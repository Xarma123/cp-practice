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
        char a[n];
        lol star = 0;
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
            if (a[i] == '*')
                star++;
        }
        bool flag = false;
        lol c = 0;
        lol ans = 0;
        for (lol i = 0; i < n; i++)
        {
            if (flag)
            {   if(c==star)break;
                if (a[i] == '*')
                    c++;
                else
                {
                    if (c < star - c)
                    { ans+= c;
                    }
                    else
                    {
                        ans+= star-c;
                    }
                }
            }
            else
            {
                if (a[i] == '*')
                {
                    flag = true;
                    c++;
                }
            }
        } 
        cout<<ans<<endl;
    }

    return 0;
}