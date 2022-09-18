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
        string a;
        cin >> a;
        string ans = "";
        ans.push_back(a[0]);

        ans.push_back(a[0]);
        string one = "";
        one.push_back(a[0]);
        string two = one;

        if (1 < n)
        {
            if (a[1] >= a[0])
                cout << ans << endl;
            else
            {
                lol p = 1;
                while (p < n && a[p] <= a[p - 1])
                { 
                    p++;
                    if(p==n)
                    break;
                }
                for (lol i = 0; i<p; i++)
                {
                    cout<<a[i];
                }
                for (lol i = p-1; i >=0; i--)
                {
                   cout<<a[i];
                } 
                cout<<endl;
                
                
            }
        }
        else
        {
            cout << ans << endl;
        }
    }

    return 0;
}