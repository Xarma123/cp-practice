#include <bits/stdc++.h>
#define lol long long
using namespace std;
string t;
string p;
vector<lol> a;
bool check(lol n)
{
    string x = t;
    for (lol i = 0; i < n; i++)
    {
        x[a[i] - 1] = '1';
    }
    lol i = 0;
    for (lol j = 0; j < x.size(); j++)
    {
        if (p[i] == x[j])
        {
            i++;
            if (i == p.size())
                break;
        }
    }
    return i == p.size();
}
int main()
{

    cin >> t >> p;

    for (lol i = 0; i < t.size(); i++)
    {
        lol f;
        cin >> f;
        a.push_back(f);
    }
    lol s = 0;
    lol e = t.size();
    while (s != e - 1)
    {
        lol m = (s + e) / 2;
        if (check(m))
            s = m;
        else
            e = m;
    }  
    cout<<s;

    return 0;
}