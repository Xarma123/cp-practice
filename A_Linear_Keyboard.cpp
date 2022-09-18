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
        string b;
        cin >> b;
        lol index[b.size()];
        for (lol i = 0; i < b.size(); i++)
        {
            for (lol j = 0; j < a.size(); j++)
            {
                if (b[i] == a[j])
                {
                    index[i] = j;
                    break;
                }
            }
        }
        lol ans = 0;
        for (lol i = 1; i < b.size(); i++)
        {
            ans += abs(index[i] - index[i - 1]);
        } 

        cout<<ans<<endl;
    }

    return 0;
}