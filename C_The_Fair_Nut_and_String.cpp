#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    string a;
    cin >> a;
    vector<lol> v;
    lol c = 0;
    for (lol i = 0; i < a.size(); i++)
    {
        if (a[i] == 'a')
            c++;
        else if (a[i] == 'b' && c > 0)
        {
            v.push_back(c);
            c = 0;
        }
    }
    if (c > 0)
        v.push_back(c);
    lol ans = 1;
    for (lol i = 0; i < v.size(); i++)
    {
        ans = (ans * 1ll * (v[i] + 1))%(1000000007);
    }
    cout << ans - 1;

    return 0;
}