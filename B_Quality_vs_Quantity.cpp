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
        lol a[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        sort(a, a + n);
        if (a[0] + a[1] < a[n - 1])
            cout << "YES" << endl;
        else
        {
            lol s = 2;
            lol e = n - 2;
            lol b = a[0] + a[1];
            lol r = a[n - 1];
            bool f = false;
            while (s < e && s < n && e < n&&e>=0)
            {
                b += a[s];
                r += a[e];
                if (r > b)
                {
                    f = true;
                    break;
                }
                s++;
                e--;
            } 
            if(f)
            cout<<"YES"<<endl;
            else
            cout<<"NO"<<endl;
        }
    }

    return 0;
}