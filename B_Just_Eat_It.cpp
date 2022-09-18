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
        lol mx = 0;
        lol mxtil = 0;
        lol s = 0;
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
            s += a[i];
            if (i < n - 1)
            {
                mxtil += a[i];
                if (mxtil < 0)
                    mxtil = 0;
                mx = max(mxtil, mx);
            }
        }
        mxtil=0;
        for (lol i = 1; i < n; i++)
        {

            mxtil += a[i];
            if (mxtil < 0)
                mxtil = 0;
            mx = max(mxtil, mx);
        } 
        if(s>mx)
        cout<<"YES"<<endl;
        else
        cout<<"NO"<<endl;
    }

    return 0;
}