#include <bits/stdc++.h>
#define lol long long
using namespace std;
bool p(string a)
{
    lol s = 0;
    lol e = a.size() - 1;
    while (s < e)
    {
        if (a[s] != a[e])
            return false;
        s++;
        e--;
    }
    return true;
}
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        lol n;
        cin >> n;
        unordered_set<string> x;
        bool f = false;
        while (n--)
        {
            string a;
            cin >> a;
            x.insert(a);
        }
    }

    return 0;
}