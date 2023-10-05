#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol a, b, c, d;
    cin >> a >> b >> c >> d;
    lol s = a + b + c + d;
    if (s % 2 == 0)
    {
        s /= 2;
        if (a == s || b == s || c == s || d == s)
            cout << "YES";
        else if (b == s - a || c == s - a || d == s - a)
            cout << "YES";
        else if (c == s - b || d == s - b)
            cout << "YES";
        else if (c + d == s)
            cout << "YES";
        else
            cout << "NO";
    }
    else
        cout << "NO";
}