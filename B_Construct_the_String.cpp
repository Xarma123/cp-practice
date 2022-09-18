#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        lol n, a, b;
        cin >> n >> a >> b;

        char c = 'a';
        string us = "";
        for (lol i = 0; i < a; i++)
        {
            if (i >= b)
            {
                us = us + "a";
            }
            else
            {
                us.push_back(c);
                c++;
            }
        }
        n -= a;
        cout << us;
        while (n >= a)
        {
           
            cout << us;
            n -= a;
        }
     
        for (lol i = 0; i < n; i++)
        {
            cout<<us[i];
        }
        cout<<endl;
        
    }

    return 0;
}