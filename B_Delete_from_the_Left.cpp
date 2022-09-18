#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    string s, t;
    cin >> s >> t;
    lol e1 = s.size();
    lol e2 = t.size();

    while (s[e1] == t[e2])
    {
        e1--;
        e2--;
        if (e1 < 0 || e2 < 0)
            break;
    } 
    cout<<e1+e2+2;

    return 0;
}