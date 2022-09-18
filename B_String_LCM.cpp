#include <bits/stdc++.h>
#define lol long long
using namespace std;
long long gcd(long long lol a, long long lol b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

long long lcm(lol a, lol b)
{
    return (a / gcd(a, b)) * b;
}
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        string s, t;
        cin >> s >> t;

        if (s.size() < t.size())
        {
            swap(s, t);
        }

        lol n = s.size();
        lol m = t.size();
        lol c = 0;
        c = lcm(n, m) / n;
        c--;
        string one = s;
        while (c--)
        {
            one = one + s;
        }
        c = one.size() / m;
        c--;

        string two = t;
        while (c--)
        {
            two = two + t;
        }

        if (one == two)
            cout << one << endl;
        else
            cout << -1 << endl;
    }

    return 0;
}