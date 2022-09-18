#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        string a;
        cin >> a;
        bool ans=true;
        set<char> x;
        for (lol i = 0; i < a.size(); i++)
        {
            if(a[i]=='R')
            {
                if(!x.count('r'))
                ans=false;

            }
            else if(a[i]=='G')
            {
                 if(!x.count('g'))
                ans=false;
            }
            else if(a[i]=='B')
            {
                  if(!x.count('b'))
                ans=false;
            }
            else
            x.insert(a[i]);
        }
        if(ans)
        cout<<"YES"<<endl;
        else
        cout<<"NO"<<endl;
    }

    return 0;
}